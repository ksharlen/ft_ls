#include "ft_ls.h"

void	sort_list_by_flags(t_filename **beg, t_ubyte *flags)
{
	if (!flags[FIND_FLAG('f')])
	{
		if (flags[FIND_FLAG('t')])
		{
			push_fullinfo_to_filename(beg);
			if (flags[FIND_FLAG('u')])
				sort_by_atime(beg);
			else
				sort_by_mtime(beg);
		}
		else
			sort_by_name(beg);
		if (flags[FIND_FLAG('r')])
			list_revers(beg);
	}
	else
		flags[FIND_FLAG('a')] = 1;
}

static void	sort_by_atime(t_filename **beg)
{
	
}