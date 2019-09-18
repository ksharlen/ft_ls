/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:48:23 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/18 07:02:48 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_filename	*merge_sort(t_filename *list,
	int (*sort_key)(t_filename *, t_filename *), t_filename *until)
{
	t_filename *left;
	t_filename *right;

	if (list == until || !list->next)
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
	return (list_filename_merge(merge_sort(left, sort_key, NULL),
		merge_sort(right, sort_key, NULL), sort_key));
}

static t_filename	*skip_sort(t_filename *beg, size_t *count)
{
	
}

static t_filename	*sort_repeat(t_filename *beg, int (*sort_key)(t_filename *, t_filename *))
{
	t_filename *begin_list;
	t_filename *beg_repeat;

	begin_list = NULL;
	if (beg)
	{
		begin_list = beg;
		while (beg->next)
		{
			if (!sort_key(beg, beg->next))
			{
				if (beg == begin_list)
				{
					begin_list = sort_repeat();
					beg = begin_list;
				}
				else
					beg = sort_repeat();
				beg = skip_sort();
			}
			else
				beg = beg->next;
		}
	}
}

t_filename			*sort_list_by_flags(t_filename **beg, t_ubyte *flags)
{
	if (!flags[FIND_FLAG('f')])
	{
		if (flags[FIND_FLAG('t')])
		{
			if (flags[FIND_FLAG('u')])
			{
				(*beg) = merge_sort(*beg, cmp_atime, NULL);
				//(*beg) = sort_repeat(*beg, cmp_atime);
			}
			else
			{
				(*beg) = merge_sort(*beg, cmp_mtime, NULL);
				//(*beg) = sort_repeat(*beg, cmp_mtime);
			}
		}
		else
			(*beg) = merge_sort(*beg, cmp_name, NULL);
		if (flags[FIND_FLAG('r')])
			list_revers(beg);
	}
	else
		flags[FIND_FLAG('a')] = 1;
	return (*beg);
}
