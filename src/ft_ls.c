#include "ft_ls.h"

static void		pull_dir(t_filename *beg, t_ubyte *flags);

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

static size_t		collect_flags(size_t argc, char *const argv[],
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

//!Начало временного кода
static void clear_filename(t_filename **beg)
{
	t_filename *res;

	if (beg && *beg)
	{
		res = (*beg);
		while (res)
		{
			(*beg) = (*beg)->next;
			ft_memdel((void **)&res->buf);
			ft_strdel((char **)&res->filename);
			ft_strdel((char **)&res->path);
			ft_strdel((char **)&res->pw_name);
			ft_strdel((char **)&res->gr_name);
			ft_memdel((void **)&res);
			res = (*beg);
		}
	}
}
//!Конец временного кода

static void			ls_internal(const char *dirname, t_ubyte *flags)
{
	t_filename		*beg;
	DIR				*dir;
	static size_t	i;

	beg = NULL;
	dir = valid_opendir(dirname);
	if (dir)
	{
		if (FIND_FLAG('R') && i != 0)
			ft_printf("%s:\n", dirname);
		push_list_filename_dir_content(dir, &beg, flags, dirname);
		push_buf_stat_to_filename(beg);
		beg = sort_list_by_flags(&beg, flags);
		print_list(beg, flags);
		closedir(dir);
		if (flags[FIND_FLAG('R')])
		{
			ft_printf("\n");
			++i;
			pull_dir(beg, flags);
		}
		clear_filename(&beg);
	}
}

static void		pull_dir(t_filename *beg, t_ubyte *flags)
{
	while (beg)
	{
		if (beg->path && (beg->f_type == D_TYPE))
			ls_internal(beg->path, flags);
		beg = beg->next;
	}
}

int		ft_ls(size_t argc, char *const argv[])
{
	t_ubyte			*flags;
	register size_t	i;

	flags = (t_ubyte[NUM_FLAGS]){0};
	if (argc > 1)
	{
		i = collect_flags(argc, argv, flags);
		if (i == argc)
			ls_internal(CURRENT_DIR, flags);
		while (i < argc)
		{
			ls_internal(argv[i], flags);
			++i;
		}
	}
	else
		ls_internal(CURRENT_DIR, flags);
	return (0);
}
