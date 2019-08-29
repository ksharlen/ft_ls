/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:58:02 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/29 10:16:28 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void def_font(char *color, const char ls_color)
{
	if (ls_color >= 'A' && ls_color <= 'Z')
		ft_strcat(color, "1m");
	else
		ft_strcat(color, "10m");
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

	color = ft_strnew(sizeof(char) * 11);
	if (!color)
		sys_errors();
	def_color(color, *(ls_color + index_color));
	def_backgrnd(color, *(ls_color + index_color + 1));
	def_font(color, *(ls_color + index_color));
}

//! НЕ ЗАБЫТЬ ПРО EXECUTE
static const char *color_stdf_or_ex(mode_t st_mode, const ssize_t index_color, const char *ls_color)
{
	char *color;

	if ((st_mode & U_X) || (st_mode & G_X) || (st_mode & O_X))
			color = def_style(ls_color, EX);
	else
		color = def_style(NULL, 0);
	return (color);
}

const char *push_color(mode_t st_mode, const char *ls_color)
{
	char *color;

	if (st_mode && S_IFDIR)
		color = def_style(ls_color, DIRF);
	else if (st_mode && S_IFLNK)
		color = def_style(ls_color, LINK);
	else if (st_mode && S_IFSOCK)
		color = def_style(ls_color, SOCKET);
	else if (st_mode && S_IFIFO)
		color = def_style(ls_color, PIPE);
	else if (st_mode && S_IFREG)
		color = color_stdf_or_ex(st_mode, EX, ls_color); //!Рассмотреть конкретнее
	else if (st_mode && S_IFBLK)
		color = def_style(ls_color, BLKF);
	else if (st_mode && S_IFCHR)
		color = def_style(ls_color, SYMF);
	else if (st_mode && S_ISUID)
		color = def_style(ls_color, SUID);
	else if (st_mode && S_ISGID)
		color == def_style(ls_color, SGID);
	else
		color == def_style(NULL, 0);
	return (color);
}
