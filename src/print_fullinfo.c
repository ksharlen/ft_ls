#include "ft_ls.h"

void	print_fullinfo(const t_filename *beg, const t_ubyte *flags)
{
	struct s_print	print_info;

	P_UNUSED(print_info);

	// if (flags[FIND_FLAG('g')])
	// {
	// 	//printf(filetype, access_permission, num_link, username, size_file, date, filename);
	// }
	// else if (flags[FIND_FLAG('l')])
	// {
	// 	while (beg)
	// 	{
	// 		printf("%s\n", pull_access_permission(beg));
	// 		//permission = pull_access_permission(beg);
	// 		// // weight = max_weight(beg, cmp_max_num_link);
	// 		// printf("weight: %d\n", weight);
	// 		//weight = ft_size_num((int)beg->info->buf.st_nlink) + 1;
	// 		//printf("filename: %s\n", beg->filename);
	// 		//printf("")
	// 		//printf("%c%s%c %*d %-*s  %-*s  %*lld %s", pull_filetype(beg), permission, pull_acl_xattr(beg->path),
	// 		//align.max_num_link, beg->info->buf.st_nlink, align.max_len_user, beg->info->pw_name,
	// 		//align.max_len_group, beg->info->gr_name, align.max_num_size_file, beg->info->buf.st_size,
	// 		//ctime(&beg->info->buf.st_mtimespec.tv_sec));
	// 		//path = cat_path_filename(beg->dirname, beg->filename);
	// 		//printf("path: %s\n", path);
	// 		//exit(EXIT_SUCCESS);
	// 		//ft_strdel(&permission);
	// 		beg = beg->next;
	// 	}
	// 	//printf(filetype, access_permission, num_link, username, size_file, date, filename);
	// }
	// else
	// 	;
	exit(EXIT_SUCCESS);
}
