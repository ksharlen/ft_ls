#include "ft_ls.h"

static void	print_lists(t_filename *beg)
{
	while (beg)
	{
		printf("beg->name: %s\n", beg->filename);
		beg = beg->next;
	}
}

static void	print_options(t_ubyte *flags)
{
	register size_t	i;

	i = 0;
	while (i < NUM_FLAGS)
	{
		printf("%u", flags[i]);
		++i;
	}
}

static void		collect_flags_files(t_filename **beg,
	size_t argc, char *const argv[], t_ubyte *flags)
	{
		register size_t i;

		i = 1;
		while (i < argc)
		{
			if (argv[i][0] == '-')
				get_options(argv[i], flags);//Если опция не поддерживается, ls авершится
			else
				list_filename_add_end(beg, argv[i]);
			++i;
		}
		valid_flags(flags);
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
	print_options(flags);
	print_lists(beg);
	return (0);
}
