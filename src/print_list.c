/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:55:09 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/17 09:55:31 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static const char	*insert_color_filename(const char *filename,
	const char *color)
{
	char *color_filename;
	char *free_string;

	color_filename = ft_strjoin(color, filename);
	CHECK_ALLOC(color_filename);
	free_string = color_filename;
	color_filename = ft_strjoin(color_filename, DEFAULT_STYLE);
	CHECK_ALLOC(color_filename);
	ft_strdel(&free_string);
	ft_strdel((char **)&color);
	return (color_filename);
}

static t_len		large_filename(t_filename *beg)
{
	t_len	len_filename;
	t_len	large_filename;

	len_filename = 0;
	large_filename = 0;
	while (beg)
	{
		if ((len_filename = ft_strlen(beg->filename)) > large_filename)
			large_filename = len_filename;
		beg = beg->next;
	}
	return (large_filename);
}

static void			simple_print_lists(t_filename *beg,
	const char *ls_color)
{
	int			len_max_filename;
	const char	*color;
	const char	*color_filename;

	len_max_filename = large_filename(beg) + (11 * 2);
	while (beg)
	{
		color = push_color(beg->buf->st_mode, ls_color);
		color_filename = insert_color_filename(beg->filename, color);
		ft_printf("%-*s ", len_max_filename, color_filename);
		ft_strdel((char **)&color_filename);
		beg = beg->next;
	}
	ft_printf("%v%s", 1, "\n");
}

void				print_list(t_filename *beg, t_ubyte *flags)
{
	const char *ls_color;

	ls_color = getenv("LSCOLORS");
	if (beg)
	{
		if (chk_flags_for_print_fullinfo(flags) == TRUE)
			print_fullinfo(beg, flags, ls_color);
		else
			simple_print_lists(beg, ls_color);
	}
}
