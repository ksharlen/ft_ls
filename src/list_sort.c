/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:48:23 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/18 17:23:49 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_filename	*merge_sort(t_filename *list,
	int (*cmp)(t_filename *, t_filename *), t_filename *until)
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
	return (list_filename_merge(merge_sort(left, cmp, NULL),
		merge_sort(right, cmp, NULL), cmp));
}

static t_filename	*find_end_repeat(t_filename *beg, int (*cmp)(t_filename *, t_filename *))
{
	t_filename *res;

	res = NULL;
	if (beg)
	{
		res = beg;
		while (res->next && !cmp(res, res->next))
		{
			//ft_printf("filename: %s\n", beg->filename);
			res = res->next;
		}
	}
	return (res);
}

static t_filename	*list_end_elem(t_filename *beg)
{
	t_filename *res;

	res = NULL;
	if (beg)
	{
		res = beg;
		while (res->next)
		{
			res = res->next;
		}
	}
	return (res);
}

static t_filename	*sort_repeat(t_filename *beg, int (*cmp)(t_filename *, t_filename *))
{
	t_filename *begin_list;
	t_filename *prev;
	t_filename *end;
	t_filename *tmp;

	begin_list = NULL;
	if (beg)
	{
		begin_list = beg;
		prev = beg;
		while (beg->next)
		{
			if (!cmp(beg, beg->next))
			{
				if (begin_list && (begin_list == beg))
				{
					end = find_end_repeat(begin_list, cmp);
					tmp = end->next;
					end->next = NULL;
					begin_list = merge_sort(begin_list, cmp_name, NULL);
					end = list_end_elem(begin_list);
					end->next = tmp;
					beg = end;
					prev = beg;
				}
				else
				{
					end = find_end_repeat(beg, cmp);
					tmp = end->next;
					end->next = NULL;
					beg = merge_sort(beg, cmp_name, NULL);
					end = list_end_elem(beg);
					prev->next = beg;
					end->next = tmp;
					beg = end;
					prev = beg;
				}
			}
			else
			{
				prev = beg;
				beg = beg->next;
			}
		}
	}
	return (begin_list); //!временно
}

//?		1)	Найти начало повторяющегося интервала
//?		2)	Найти последний повторяющийся элемент
//?		3)	Сохранить элемент после последнего(что бы не потерять связь)
//?		4)	занулить конечный повторный элемент
//?		5)	отсортировать повторки через merge_sort
//?		6)	Найти последний элемент в отсортированном списке
//?		7)	Присвоить ему сохраненную связь
//?		8)	Перенести указатель на конец репитов

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
				(*beg) = sort_repeat(*beg, cmp_mtime);
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
