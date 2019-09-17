/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:41:31 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/17 09:42:39 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	flag_error(t_ubyte sym)
{
	ft_printf("%vft_ls: illegal option -- %c\n%s", 2, sym, EFLAGS);
	exit(EXIT_SUCCESS);
}

void		valid_flags(const t_ubyte *flags)
{
	register size_t	i;
	t_ubyte			sym;

	i = 1;
	while (i < NUM_FLAGS)
	{
		if (flags[i])
			if (!ft_strchr(FLAGS, sym = (i + (i >= 27 ? 38 : 'a' - 1))))
				flag_error(sym);
		++i;
	}
}

int			get_options(const char *options, t_ubyte *flags)
{
	++options;
	while (*options)
	{
		if (FLAG_VALID(*options))
			flags[(FLAG_LOW_REG(*options) ? (*options - 'a') + 1
			: (*options - 38))] = FLAG_ON;
		else
			flag_error(*(t_ubyte *)options);
		++options;
	}
	return (SUCCESSFUL_COMPLETION);
}

int			chk_flags_for_create_fullinfo(t_ubyte *flags)
{
	if (flags[FIND_FLAG('l')] || flags[FIND_FLAG('g')] || flags[FIND_FLAG('t')])
		return (TRUE);
	else
		return (FALSE);
}

int			chk_flags_for_print_fullinfo(t_ubyte *flags)
{
	if (flags[FIND_FLAG('l')] || flags[FIND_FLAG('g')])
		return (TRUE);
	else
		return (FALSE);
}
