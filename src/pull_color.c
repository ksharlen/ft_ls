/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:58:02 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/29 08:59:50 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


static void	pull_color(char ls_color, char *color)
{
	if (ls_color == 'a')
		ft_strcpy(color, "\e[;30m");
	else if (ls_color == 'b')
		ft_strcpy(color, "\e[;31m");
	else if (ls_color == 'c')
		ft_strcpy(color, "\e[;32m");
	else if (ls_color == 'd')
		ft_strcpy(color, "\e[;33m");
	else if (ls_color == 'e')
		ft_strcpy(color, "\e[;34m");
	else if (ls_color == 'f')
		ft_strcpy(color, "\e[;35m");
	else if (ls_color == 'g')
		ft_strcpy(color, "\e[;36m");
	else if (ls_color == 'h')
		ft_strcpy(color, "\e[;37m");
	else
		ft_strcpy(color, "\e[;37m");
}

static void	pull_color_font(char ls_color, char *color)
{
	pull_color(ls_color + 32, color);
	ft_strcpy(color + 5, ";1m");
}

static const char *def_color(const char *ls_color, const ssize_t index_color)
{
	char *color;

	ls_color += index_color;

	if (*ls_color > 64 && *ls_color < 91)
	{
		color = ft_strnew(sizeof(char) * 8);
		pull_color_font(*ls_color, color);
	}
	else (*ls_color > 96 && *ls_color < 123)
	{
		color = ft_strnew(sizeof(char) * 6);
		color = pull_color(*ls_color, color);
	}
	return (color);
}

const char *push_color(uint8_t f_type, const char *ls_color)
{
	char *color;

	if (f_type == D_TYPE)
		color = def_color(ls_color, DIR);
	else if (f_type == L_TYPE)
		color = def_color(ls_color, LINK);
	else if (f_type == S_TYPE)
		color = def_color(ls_color, SOCKET);
	else if (f_type == F_TYPE)
		color = def_color(ls_color, PIPE);
	else if (f_type == R_TYPE)
		color = def_color(ls_color, EX); //!Рассмотреть конкретнее
	else if (f_type == B_TYPE)
		color = def_color(ls_color, BLKF);
	else if (f_type == C_TYPE)
		color = def_color(ls_color, SYMF);
	return (color);
}


// 	if (f_type == C_TYPE)
// 		color = def_color(color, SYMF);
// 	else if (f_type == D_TYPE)
// 		color = def_color(color, DIR);
// 	else if (f_type == B_TYPE)
// 		color = def_color(color, BLKF);
// 	else if (f_type == L_TYPE)
// 		color = def_color(color, LINK);
// 	else if (f_type == S_TYPE)
// 		color = def_color(color, SOCKET);
// 	else if (f_type == W_TYPE)
		
// 	return (color);
// }