#include "ft_ls.h"

static void		pull_dir(t_filename *beg, t_ubyte *flags);

// static void print_dir(t_filename *beg)
// {
// 	if (beg)
// 		while (beg)
// 		{
// 			ft_printf("filename: %s\n", beg->filename);
// 			ft_printf("dirname: %s\n", beg->dirname);
// 			ft_printf("path: %s\n\n", beg->path);
// 			beg = beg->next;
// 		}
// }

// static void	print_lists_p(t_filename *beg)
// {
// 	while (beg)
// 	{
// 		if (!ft_strncmp(beg->filename, ".", 1) || !ft_strncmp(beg->filename, "..", 2))
// 			;
// 		else
// 			ft_printf("%s	", beg->filename);
// 		beg = beg->next;
// 	}
// 	ft_printf("\n");
// }

// static void	print_options(t_ubyte *flags)
// {
// 	register size_t	i;

// 	i = 0;
// 	while (i < NUM_FLAGS)
// 	{
// 		ft_printf("%u", flags[i]);
// 		++i;
// 	}
// }

static size_t	push_flags(size_t argc, char *const argv[], t_ubyte *flags)
{
	register size_t i;

	flags[0] = FLAG_ON;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1])
	{
		if (argv[i][1])
		{
			get_options(argv[i], flags); //Ф-ия что-то будет возвращать
			++i;
		}
		else
			return (i);
	}
	return (i);//Сменить на макрос
}

static size_t		collect_flags(size_t argc, char *const argv[],
	t_ubyte *flags)
	{
		size_t	skip_opt_argv;

		skip_opt_argv = 0;
		if (CHECK_KEY(argv[1]))
		{
			skip_opt_argv = push_flags(argc, argv, flags);
			valid_flags(flags);
		}
		return (skip_opt_argv);
	}

//!Начало временного кода
static void clear_filename(t_filename **beg)
{
	t_filename *res;
//	t_filename *tmp;

	if (beg && *beg)
	{
		res = (*beg);
		while (res)
		{
			//printf("1\n");
			(*beg) = (*beg)->next;
			ft_memdel((void **)&res->buf);
			ft_strdel((char **)&res->filename);
			ft_strdel((char **)&res->path);
			ft_strdel((char **)&res->pw_name);
			ft_strdel((char **)&res->gr_name);
			ft_memdel((void **)&res);
			res = (*beg);
		}
	}
}
//!Конец временного кода

static void			ls_internal(const char *dirname, t_ubyte *flags)
{
	//!Не забыть сделать closedir and free
	t_filename		*beg;
	DIR				*dir;

	//dir = opendir(dir);//Проверить errno на значение 20(это не каталог)//так же проверить на что не нашел.
	beg = NULL;
	dir = valid_opendir(dirname);
	if (dir)
	{
		push_list_filename_dir_content(dir, &beg, flags, dirname);
		push_buf_stat_to_filename(beg);
		beg = sort_list_by_flags(&beg, flags);
		print_list(beg, flags);
		closedir(dir);
		if (flags[FIND_FLAG('R')])
			pull_dir(beg, flags);
		clear_filename(&beg);
		//!После того как идем вверх начинаем фришить
	}
	// else
		; //либо тут невалидный файл либо тут просто файл через рекурсию
}

static void		pull_dir(t_filename *beg, t_ubyte *flags)
{
	while (beg)
	{
		if (beg->path && (beg->f_type == D_TYPE))
			ls_internal(beg->path, flags);
		beg = beg->next;
	}
}

int		ft_ls(size_t argc, char *const argv[])
{
	t_ubyte			*flags;
	register size_t	i;

	flags = (t_ubyte[NUM_FLAGS]){0};
	if (argc > 1)
	{
		i = collect_flags(argc, argv, flags);
		if (i == argc)
			ls_internal(CURRENT_DIR, flags);
		while (i < argc)
		{
			ls_internal(argv[i], flags);
			++i;
		}
	}
	else
		ls_internal(CURRENT_DIR, flags);
	return (0);
}

/*	Работа ft_ls:
	1)	собрать все флаги до первого - или символа отличного от флага
	//2)	Создать структуру на основе собранных флагов (не уверен на счет этого)
		?примечание: флаги вывода информации и сортировки должны быть внутри рекурсивной ф-ии
	3)	Запустить главную рекурсивную ф-ию.
*/

/* Работа рекурсивной ф-ии:
	1) Открыть директорию(opendir)
		1.1)	обратотать ошибки если директории нет или это не директория
	2) Считать все содержимое директории(readdir), заполняя список этими данными (Считывание будет происходить в цикле)
	while (readdir(filename)) //Пока папка не прочитанна полностью
	{
		?Примечания: на этом этапе нас интерисуют только флаги вывода информации!!!
		2.1)	создать элемент структуры, положить туда filename (будем сразу трогать ф-ию list_add)
		2.2)	в зависимости от флагов создать(или не создать)структуру дополнительной информации(Она создается елси есть флаг -t или -u)
				2.2.1)	Если есть только флаг -а, доп структура не создается, просто выводяться невидимые файлы
				2.2.2)	Если есть -l или -g структуру надо создать(t_fullinfo)
				2.2.3)	Если есть -d смотреть по компбинации других флагов с выводом информации
	}
	?примечание:	это не выполниться, если opendir пытался открыть файл, а не директорию(Рекурсия возвращается)
	3) В зависимости от флагов вывода, обработать некоторые переменные структуры(st_mode)
	4)	Проверить флаги сортировки, если они есть, отсортировать данные(подумать над сортировкой если есть несколько сортировочных флагов)
		4.1)	Если есть флаг -f, все флаги сортировки игнорируются(Поэтому сначала проверяем его наличие)
	5)	Создать буфер, куда перенести весь наш список
	6)	Вывести буффер в зависимости от флагов вывода
	7)	вызываем эту ф-ию рекурсивно и передаем туда первый элемент списка(возвращаемся к пункту 1))
*/
