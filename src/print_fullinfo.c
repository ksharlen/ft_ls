#include "ft_ls.h"

void	print_fullinfo(const t_filename *beg, const t_ubyte *flags)
{
	char *permission;

	if (flags[FIND_FLAG('g')])
	{
		//printf(filetype, access_permission, num_link, username, size_file, date, filename);
	}
	else if (flags[FIND_FLAG('l')])
	{
		while (beg)
		{
			permission = pull_access_permission(beg);
			printf("%c%s%c\n", pull_filetype(beg), permission, );
			ft_strdel(&permission);
			beg = beg->next;
		}
		//printf(filetype, access_permission, num_link, username, size_file, date, filename);
	}
	else
		;
	exit(EXIT_SUCCESS);
}
