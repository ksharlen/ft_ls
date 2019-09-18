/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:48:23 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/18 12:28:36 by ksharlen         ###   ########.fr       */
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

static t_filename	*find_end_repeat(t_filename *beg, int (*cmp)(t_filename *, t_filename *))
{
	if (beg)
	{
		while (beg->next && !cmp(beg, beg->next))
		{
			ft_printf("filename: %s\n", beg->filename);
			beg = beg->next;
		}
	}
	return (beg);
}

static t_filename	*sort_repeat(t_filename *beg, int (*sort_key)(t_filename *, t_filename *))
{
	t_filename *begin_list;
	t_filename *end;
	t_filename *tmp;

	begin_list = NULL;
	if (beg)
	{
		begin_list = beg;
		while (beg->next)
		{
			if (!sort_key(beg, beg->next))
			{
				end = find_end_repeat(beg, sort_key);
				ft_printf("end: %s\n", end->filename);
				tmp = end->next;
				beg = end;
			}
			else
				beg = beg->next;
		}
	}
	return (NULL); //!временно
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
				//exit(EXIT_SUCCESS);
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
