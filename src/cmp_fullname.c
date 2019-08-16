#include "ft_ls.h"

#if __linux__

int		cmp_atime(t_filename *one, t_filename *two)
{
	if (one->info->buf.st_atime < two->info->buf.st_atime)
		return (TRUE);
	else
		return (FALSE);
}

int		cmp_mtime(t_filename *one, t_filename *two)
{
	if (one->info->buf.st_mtime < two->info->buf.st_mtime)
		return (TRUE);
	else
		return (FALSE);
}

int		cmp_name(t_filename *one, t_filename *two)
{
	if (ft_strcmp(one->filename, two->filename) < 0)
		return (TRUE);
	else
		return (FALSE);
}

#endif

#if __APPLE__

//...

#endif
