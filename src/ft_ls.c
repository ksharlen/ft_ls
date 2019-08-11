#include "ft_ls.h"

static void	print_lists(t_filename *beg)
{
	while (beg)
	{
		printf("beg->name: %s\n", beg->filename);
		beg = beg->next;
	}
}

static void	print_options(l_utype *flags)
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
	int argc, char *const argv[], l_utype *flags)
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

int		ft_ls(int argc, char *const argv[])
{
	t_filename	*beg;
	l_utype		flags[NUM_FLAGS];

	beg = NULL;
	ft_bzero(flags, NUM_FLAGS);
	//Параллельно собирать флаги и именя файлов
	if (argc > 1)
		collect_flags_files(&beg, argc, argv, flags);
		//list_push_filename(&beg, argc, argv);
	else
		;//вывести содержимое текущей директории
		//Могут быть другие ключи
		//Надо будет проверить первый элемент flags на их наличие
	//printf("list_size: %ld\n", list_filename_size(beg));
	print_options(flags);
	print_lists(beg);
}
