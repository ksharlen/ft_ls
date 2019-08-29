/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:58:02 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/29 08:24:00 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const char *pull_color(uint8_t f_type, const char *color)
{
	char *color;

	if (f_type == D_TYPE)
		color = def_color(color, DIR);
	else if (f_type == L_TYPE)
		color = def_color(color, LINK);
	else if (f_type == S_TYPE)
		color = def_color(color, SOCKET);
	else if (f_type == F_TYPE)
		color = def_color(color, PIPE);
	else if (f_type == R_TYPE)
		color = def_color(color, EX); //!Рассмотреть конкретнее
	else if (f_type == B_TYPE)
		color = def_color(color, BLKF);
	else if (f_type == C_TYPE)
		color = def_color(color, SYMF);
	else if (f_type == )


	if (f_type == C_TYPE)
		color = def_color(color, SYMF);
	else if (f_type == D_TYPE)
		color = def_color(color, DIR);
	else if (f_type == B_TYPE)
		color = def_color(color, BLKF);
	else if (f_type == L_TYPE)
		color = def_color(color, LINK);
	else if (f_type == S_TYPE)
		color = def_color(color, SOCKET);
	else if (f_type == W_TYPE)
		
	return (color);
}