#include "ft_ls.h"

static struct stat	*buf_stat_create(void)
{
	struct stat		*new;

	new = (struct stat *)ft_memalloc(sizeof(struct stat));
	if (!new)
		sys_errors();
	return (new);
}

static void			buf_stat_add_to_filename(t_filename *beg)
{
	if (beg)
	{
		while (beg)
		{
			beg->buf = buf_stat_create();
			beg = beg->next;
		}
	}
}

void	push_buf_stat_to_filename(t_filename *beg, t_ubyte *flags)
{
	if (chk_flags_for_create_fullinfo(flags) == TRUE)
	{
		buf_stat_add_to_filename(beg);
		while (beg)
		{
			beg->path = cat_path_filename(beg->dirname, beg->filename);
			//beg->path = cat_path_filename()
			//beg->dirname = ft_strjoin(dirname, "/");//Думаю это будет не тут
			//!Зафришить
			//beg->dirname = ft_strjoin(beg->dirname, beg->filename);
			valid_stat(beg->path, beg->buf, beg->f_type);
			beg = beg->next;
		}
	}
}