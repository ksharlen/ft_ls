/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:58:02 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/29 21:42:52 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void def_font(char *color, const char ls_color)
{
	if (ls_color >= 'A' && ls_color <= 'Z')
		ft_strcat(color, "1m");
	else
		ft_strcat(color, "22m");
}

static void def_backgrnd(char *color, const char ls_color)
{
	if (ls_color == 'a' || ls_color == 'A')
		ft_strcat(color, "40;");
	else if (ls_color == 'b' || ls_color == 'B')
		ft_strcat(color, "41;");
	else if (ls_color == 'c' || ls_color == 'C')
		ft_strcat(color, "42;");
	else if (ls_color == 'd' || ls_color == 'D')
		ft_strcat(color, "43;");
	else if (ls_color == 'e' || ls_color == 'E')
		ft_strcat(color, "44;");
	else if (ls_color == 'f' || ls_color == 'F')
		ft_strcat(color, "45;");
	else if (ls_color == 'g' || ls_color == 'G')
		ft_strcat(color, "46;");
	else if (ls_color == 'h' || ls_color == 'H')
		ft_strcat(color, "47;");
	else
		ft_strcat(color, "49;");
}

static void def_color(char *color, const char ls_color)
{
	if (ls_color == 'a' || ls_color == 'A')
		ft_strcpy(color, "\e[30;");
	else if (ls_color == 'b' || ls_color == 'B')
		ft_strcpy(color, "\e[31;");
	else if (ls_color == 'c' || ls_color == 'C')
		ft_strcpy(color, "\e[32;");
	else if (ls_color == 'd' || ls_color == 'D')
		ft_strcpy(color, "\e[33;");
	else if (ls_color == 'e' || ls_color == 'E')
		ft_strcpy(color, "\e[34;");
	else if (ls_color == 'f' || ls_color == 'F')
		ft_strcpy(color, "\e[35;");
	else if (ls_color == 'g' || ls_color == 'G')
		ft_strcpy(color, "\e[36;");
	else if (ls_color == 'h' || ls_color == 'H')
		ft_strcpy(color, "\e[37;");
	else
		ft_strcpy(color, "\e[39;");
}

static const char *def_style(const char *ls_color, const ssize_t index_color)
{
	char *color;
	char sym;

	sym = 0;
	color = ft_strnew(sizeof(char) * 11);
	if (!color)
		sys_errors();
	if (ls_color)
		sym = *(ls_color + index_color);
	def_color(color, sym);
	if (ls_color)
		sym = *(ls_color + index_color + 1);
	def_backgrnd(color, sym);
	if (ls_color)
		sym = *(ls_color + index_color);
	def_font(color, sym);
	return (color);
}

static const char *color_dir(mode_t st_mode, const char *ls_color)
{
	const char *color;

	if (st_mode & O_W)
	{
		if (st_mode & O_T)
			
	}
}
//! НЕ ЗАБЫТЬ ПРО EXECUTE
static const char *color_stdf_or_ex(mode_t st_mode, const char *ls_color)
{
	const char *color;

	if ((st_mode & U_X) || (st_mode & G_X) || (st_mode & O_X))
			color = def_style(ls_color, EX);
	else
		color = def_style(NULL, 0);
	return (color);
}

const char *push_color(mode_t st_mode, const char *ls_color)
{
	const char *color;

	if (S_ISDIR(st_mode))
		color = color_dir(st_mode, ls_color);
		//color = def_style(ls_color, DIRF);
	else if (S_ISLNK(st_mode))
		color = def_style(ls_color, LINK);
	else if (S_ISSOCK(st_mode))
		color = def_style(ls_color, SOCKET);
	else if (S_ISFIFO(st_mode))
		color = def_style(ls_color, PIPE);
	else if (S_ISREG(st_mode))
		color = color_stdf_or_ex(st_mode, ls_color);
	else if (S_ISBLK(st_mode))
		color = def_style(ls_color, BLKF);
	else if (S_ISCHR(st_mode))
		color = def_style(ls_color, SYMF);
	else if (st_mode & S_ISUID)
		color = def_style(ls_color, SUID);
	else if (st_mode & S_ISGID)
		color = def_style(ls_color, SGID);
	else if (st_mode & S_ISVTX)
		color = def_style(ls_color, DSCKB);
	else if (st_mode & S_IXGRP)
		color = def_style(ls_color, DSCKNB);
	else
		color = def_style(NULL, 0);
	return (color);
}
