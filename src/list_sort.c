#include "ft_ls.h"

static t_filename *merge_sort(t_filename *list, int (*sort_key)(t_filename *, t_filename *))
{
	t_filename *left;
	t_filename *right;

	if (!list || !list->next)
		return (list);
	left = list;
	right = left->next;
	while (right && right->next)
	{
		list = list->next;
		right = right->next->next;
	}
	right = list->next;
	list->next = NULL;
	return (list_filename_merge(merge_sort(left, sort_key), right, sort_key));
}

void	sort_list_by_flags(t_filename **beg, t_ubyte *flags)
{
	if (!flags[FIND_FLAG('f')])
	{
		if (flags[FIND_FLAG('t')])
		{
			push_fullinfo_to_filename(beg);
			if (flags[FIND_FLAG('u')])
				merge_sort(*beg, cmp_atime);
			else
				merge_sort(*beg, cmp_mtime);
		}
		else
			merge_sort(*beg, cmp_name);
		if (flags[FIND_FLAG('r')])
			list_revers(beg);
	}
	else
		flags[FIND_FLAG('a')] = 1;
}
