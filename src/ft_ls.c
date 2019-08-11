#include "ft_ls.h"

static void	print_lists(t_filename *beg)
{
	while (beg)
	{
		printf("beg->name: %s\n", beg->filename);
		beg = beg->next;
	}
}

int		ft_ls(int argc, char *const argv[])
{
	t_filename	*beg;
	l_utype		flags[NUM_FLAGS];

	beg = NULL;
	//Параллельно собирать флаги и именя файлов
	if (argc > 1)
		list_push_filename(&beg, argc, argv);
	else
		;//вывести содержимое текущей директории
		//Могут быть другие ключи
	print_lists(beg);
}
