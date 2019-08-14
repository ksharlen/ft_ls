#include "ft_ls.h"

static void	print_lists(t_filename *beg)
{
	while (beg)
	{
		printf("%s	", beg->filename);
		beg = beg->next;
	}
	printf("\n");
}

// static void	print_options(t_ubyte *flags)
// {
// 	register size_t	i;

// 	i = 0;
// 	while (i < NUM_FLAGS)
// 	{
// 		printf("%u", flags[i]);
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
	return (i);
}

static size_t		collect_flags(size_t argc, char *const argv[],
	t_ubyte *flags)
	{
		register size_t i;

		i = 1;
		if (CHECK_KEY(argv[i]))
		{
			i += push_flags(argc, argv, flags);
			valid_flags(flags);
		}
		return (i);
	}

static void			ls_internal(const char *filename, t_ubyte *flags)
{
	//!Не забыть сделать closedir and free
	t_filename		*beg;
	DIR				*dir;

	P_UNUSED(flags);

	//dir = opendir(dir);//Проверить errno на значение 20(это не каталог)//так же проверить на что не нашел.
	//printf("here\n");
	beg = NULL;
	dir = valid_opendir(filename);
	if (dir)
	{
		push_list_filename_dir_content(dir, &beg);
		print_lists(beg);
		//sort_list_by_flags(&beg, flags);

		//Тут список уже создан нужно отсортировать
	}
}

int		ft_ls(size_t argc, char *const argv[])
{
	t_ubyte			*flags;
	register size_t	i;

	flags = (t_ubyte[NUM_FLAGS]){0}; //ЭТО РАБОТАЕТ!!!!!
	if (argc > 1)
	{
		i = collect_flags(argc, argv, flags);
		printf("i: %ld\n", i);
		while (i < argc)
		{
			ls_internal(argv[i], flags);
			++i;
		}
	}
	else
		ls_internal(CURRENT_DIR, flags);//вывести содержимое текущей директории
		//Могут быть другие ключи
		//Надо будет проверить первый элемент flags на их наличие
	//print_options(flags);
	//print_lists(beg);
	//!Подумать над сортировкой если указаны аргументы
	return (0);
}

/*	Рабоат ft_ls:
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

