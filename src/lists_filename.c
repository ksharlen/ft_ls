#include "ft_ls.h"

size_t				list_filename_size(t_filename *beg)
{
	if (!beg->next)
		return (1);
	return (1 + list_filename_size(beg->next));
}

static t_filename	*list_filename_create(char *filename)
{
	t_filename	*new;

	new = (t_filename *)ft_memalloc(sizeof(t_filename));
	if (!new)
	{
		perror(NULL);
		exit(EXIT_SUCCESS);//Тут еще подумать
	}
	new->filename = filename;
	new->full_descript = NULL;
	return (new);
}

void		list_filename_add_end(t_filename **beg, char *filename)
{
	t_filename *res;

	if (beg)
	{
		if (*beg)
		{
			res = (*beg);
			while (res->next)
				res = res->next;
			res->next = list_filename_create(filename);
		}
		else
			(*beg) = list_filename_create(filename);
	}
}

// int		list_push_filename(t_filename **beg, int argc, char *const argv[])
// {
// 	register size_t i;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		list_filename_add_end(beg, argv[i]);
// 		++i;
// 	}
// 	return (0);
// }

//list_filename_delete()
//list_filename_free()
//list_filename_size()
