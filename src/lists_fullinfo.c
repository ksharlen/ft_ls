#include "ft_ls.h"

static t_fullinfo	*list_fullinfo_create(void)
{
	t_fullinfo	*new;

	new = (t_fullinfo *)malloc(sizeof(t_fullinfo));
	if (!new)
		sys_errors();
	new->pw_name = NULL;
	new->gr_name = NULL;
	return (new);
}

static void		list_add_fullinfo_to_filename(t_filename *beg)
{
	if (beg)
	{
		while (beg)
		{
			beg->info = list_fullinfo_create();
			beg = beg->next;
		}
	}
}

void	push_fullinfo_to_filename(t_filename *beg, t_ubyte *flags)
{
	if (chk_flags_for_create_fullinfo(flags) == TRUE)
	{
		list_add_fullinfo_to_filename(beg);
		while (beg)
		{
			beg->path = cat_path_filename(beg->dirname, beg->filename);
			//beg->path = cat_path_filename()
			//beg->dirname = ft_strjoin(dirname, "/");//Думаю это будет не тут
			//!Зафришить
			//beg->dirname = ft_strjoin(beg->dirname, beg->filename);
			valid_stat(beg->path, &beg->info->buf);
			beg = beg->next;
		}
		//exit(EXIT_SUCCESS);
	}
}
