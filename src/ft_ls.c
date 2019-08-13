#include "ft_ls.h"

// static void	print_lists(t_filename *beg)
// {
// 	while (beg)
// 	{
// 		printf("beg->name: %s\n", beg->filename);
// 		beg = beg->next;
// 	}
// }

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

static size_t	collect_flags(size_t argc, char *const argv[], t_ubyte *flags)
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

static void		collect_flags_files(t_filename **beg,
	size_t argc, char *const argv[], t_ubyte *flags)
	{
		register size_t i;

		i = 1;
		if (CHECK_KEY(argv[i]))
		{
			i += collect_flags(argc, argv, flags);
			valid_flags(flags);
		}
		while (i < argc)
		{
			list_filename_add_end(beg, argv[i]);//Тут надо подумать про ф-ию, нужна ли она вообще?
			++i;
		}
	}

int		ft_ls(size_t argc, char *const argv[])
{
	t_filename	*beg;
	t_ubyte		*flags;

	beg = NULL;
	flags = (t_ubyte[NUM_FLAGS]){0}; //ЭТО РАБОТАЕТ!!!!!
	if (argc > 1)
		collect_flags_files(&beg, argc, argv, flags);
	else
		;//вывести содержимое текущей директории
		//Могут быть другие ключи
		//Надо будет проверить первый элемент flags на их наличие
	//print_options(flags);
	//print_lists(beg);
	return (0);
}
