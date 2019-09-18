/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:42:58 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/18 21:51:48 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	push_flags(size_t argc, char *const argv[], t_ubyte *flags)
{
	register size_t i;

	flags[0] = FLAG_ON;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1])
	{
		if (argv[i][1])
		{
			get_options(argv[i], flags);
			++i;
		}
		else
			return (i);
	}
	return (i);
}

static size_t	collect_flags(size_t argc, char *const argv[],
t_ubyte *flags)
{
	size_t	skip_opt_argv;

	skip_opt_argv = 0;
	if (CHECK_KEY(argv[1]))
	{
		skip_opt_argv = push_flags(argc, argv, flags);
		valid_flags(flags);
	}
	return (skip_opt_argv);
}

static void		ls_internal(const char *dirname, t_ubyte *flags)
{
	t_filename		*beg;
	DIR				*dir;
	static size_t	i;

	beg = NULL;
	dir = valid_opendir(dirname);
	if (dir)
	{
		if (FIND_FLAG('R') && i != 0)
			ft_printf("\n%s:\n", dirname);
		push_list_filename_dir_content(dir, &beg, flags, dirname);
		push_buf_stat_to_filename(beg);
		beg = sort_list_by_flags(&beg, flags);
		print_list(beg, flags);
		if ((closedir(dir) == -1))
			sys_errors();
		if (flags[FIND_FLAG('R')])
		{
			++i;
			pull_dir(beg, flags);
		}
		clear_filename(&beg);
	}
}

void			pull_dir(t_filename *beg, t_ubyte *flags)
{
	while (beg)
	{
		if (beg->path && (beg->f_type == D_TYPE))
			ls_internal(beg->path, flags);
		beg = beg->next;
	}
}

int				ft_ls(const size_t argc, char *const argv[])
{
	t_ubyte			*flags;
	register size_t	i;
	t_ubyte			flag_for_print_dir;

	flags = (t_ubyte[NUM_FLAGS]){0};
	if (argc > 1)
	{
		i = collect_flags(argc, argv, flags);
		i = (!i ? ++i : i);
		if (i == argc)
			ls_internal(CURRENT_DIR, flags);
		else
		{
			flag_for_print_dir = (argc - i + 1 > 1) ? FLAG_ON : FLAG_OFF;
			while ((argc - i) > 0)
			{
				if (flag_for_print_dir && argc > 2 && !FIND_FLAG('R'))// && i + 1 < argc + 1)
					ft_printf("%s:\n", argv[i]);
				else if (FIND_FLAG('R') && i == 1)
					ft_printf("%s:\n", argv[i]);
				ls_internal(argv[i], flags);
				(((argc - 1) - i)) && !FIND_FLAG('R') ? ft_printf("\n") : 0;
				++i;
			}
		}
	}
	else
		ls_internal(CURRENT_DIR, flags);
	return (0);
}
