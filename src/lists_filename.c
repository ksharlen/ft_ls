#include "ft_ls.h"

size_t				list_filename_size(t_filename *beg)
{
	if (!beg->next)
		return (1);
	return (1 + list_filename_size(beg->next));
}

static t_filename	*list_filename_create(const char *filename, uint8_t f_type)
{
	t_filename	*new;

	new = (t_filename *)ft_memalloc(sizeof(t_filename));
	if (!new)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}//Добавить врапп
	new->filename = filename;
	new->f_type = f_type;
	new->next = NULL;
	new->info = NULL;
	return (new);
}

void	list_filename_add_end(t_filename **beg, const char *filename, uint8_t f_type)
{
	t_filename	*res;
	t_filename	*new;

	new = list_filename_create(filename, f_type);
	if (beg)
	{
		if (*beg)
		{
			res = (*beg);
			while (res->next)
				res = res->next;
			res->next = new;
		}
		else
			(*beg) = new;
	}
}

void	push_list_filename_dir_content(DIR *dir, t_filename **beg)
{
	struct dirent *dent;

	while ((dent = valid_readdir(dir)))
	{
		list_filename_add_end(beg, dent->d_name, dent->d_type);
	}
}

//list_filename_delete()
//list_filename_free()
//list_filename_size()
