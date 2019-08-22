#include "ft_ls.h"

void	print_fullinfo(const t_filename *beg, const t_ubyte *flags)
{
	char *permission;
	int	max_num_link;
	int	max_num_size_file;

	max_weight(beg, &max_num_link, &max_num_size_file);
	//printf("num_link: %d\nnum_size: %d\n", max_num_link, max_num_size_file);
	//exit(EXIT_SUCCESS);
	if (flags[FIND_FLAG('g')])
	{
		//printf(filetype, access_permission, num_link, username, size_file, date, filename);
	}
	else if (flags[FIND_FLAG('l')])
	{
		while (beg)
		{
			permission = pull_access_permission(beg);
			// // weight = max_weight(beg, cmp_max_num_link);
			// printf("weight: %d\n", weight);
			//weight = ft_size_num((int)beg->info->buf.st_nlink) + 1;
			//printf("filename: %s\n", beg->filename);
			//printf("")
			printf("%c%s%c %*d\n", pull_filetype(beg), permission, pull_acl_xattr(beg->path),
			max_num_link, beg->info->buf.st_nlink);
			//path = cat_path_filename(beg->dirname, beg->filename);
			//printf("path: %s\n", path);
			//exit(EXIT_SUCCESS);
			//ft_strdel(&permission);
			beg = beg->next;
		}
		//printf(filetype, access_permission, num_link, username, size_file, date, filename);
	}
	else
		;
	exit(EXIT_SUCCESS);
}
