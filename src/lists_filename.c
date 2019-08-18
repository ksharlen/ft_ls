#include "ft_ls.h"

void		list_revers(t_filename **beg)
{
	t_filename *curr;
	t_filename *next;
	t_filename *prev;

	curr = (*beg);
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	(*beg) = prev;
}

t_filename	*list_filename_merge(t_filename *l_one, t_filename *l_two, int (*key)(t_filename *, t_filename *))
{
	t_filename tmp;
	t_filename *new = &tmp;
	t_filename *res = new;

	//new = &tmp;
	//res = new;
	while (l_one && l_two)
	{
		if (key(l_one, l_two) == TRUE)
		{
			res->next = l_one;
			res = l_one;
			l_one = l_one->next;
		}
		else
		{
			res->next = l_two;
			res = l_two;
			l_two = l_two->next;
		}
	}
	res->next = (l_one ? l_one : l_two);
	return (new->next);
}

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
		sys_errors();
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

void	push_list_filename_dir_content(DIR *dir, t_filename **beg, t_ubyte *flags)
{
	struct dirent *dent;

	while ((dent = valid_readdir(dir)))
	{
		if (flags[FIND_FLAG('f')] || flags[FIND_FLAG('a')])
			list_filename_add_end(beg, dent->d_name, dent->d_type);
		else
		{
			if (!ft_strncmp(dent->d_name, ".", 1))
				;
			else
				list_filename_add_end(beg, dent->d_name, dent->d_type);
		}
	}
}

//list_filename_delete()
//list_filename_free()
//list_filename_size()
