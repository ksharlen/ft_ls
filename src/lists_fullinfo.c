#include "ft_ls.h"

static t_fullinfo	*list_fullinfo_create(void)
{
	t_fullinfo	*new;

	new = (t_fullinfo *)malloc(sizeof(t_fullinfo));
	if (!new)
		sys_errors();
	new->pw_name = NULL;
	new->gr_name = NULL;
	return (new);
}

static void		list_add_fullinfo_to_filename(t_filename *beg)
{
	if (beg)
	{
		while (beg)
		{
			beg->info = list_fullinfo_create();
			beg = beg->next;
		}
	}
}

void	push_fullinfo_to_filename(t_filename **beg)
{
	t_filename	*elem;

	elem = (*beg);
	list_add_fullinfo_to_filename(*beg);
	while (elem)
	{
		valid_stat(elem->filename, &elem->info->buf);
		elem = elem->next;
	}
}