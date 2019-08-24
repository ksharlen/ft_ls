#include "ft_ls.h"

static void	fill_s_print(const t_filename *beg, const t_ubyte *flags, struct s_print *info)
{
	info->filetype = pull_filetype(beg->f_type);
	info->permission = pull_access_permission(beg->buf->st_mode);
	info->acl_xattr = pull_acl_xattr(beg->path);
	info->num_link = beg->buf->st_nlink;
	info->group = beg->gr_name;
	if (flags[FIND_FLAG('g')])
		info->user = "";
	else
		info->user = beg->pw_name;
	info->size_file = beg->buf->st_size;
	info->date = pull_date(beg, flags);
	info->filename = beg->filename;
	//!info->date need free
}

void	print_fullinfo(const t_filename *beg, const t_ubyte *flags)
{
	struct s_print	print_info;
	struct s_num	align;

	//тут будет определение выравнивания
	max_len_elem(beg, &align);
	if (flags[FIND_FLAG('g')])
		align.max_len_user = 0;
	//printf("u: %d\ng: %d\n", align.max_len_user, align.max_len_group);
	//exit(EXIT_SUCCESS);
	printf("total %lld\n", align.total);
	while (beg)
	{
		fill_s_print(beg, flags, &print_info);
		printf("%c%s%c %*d %*s  %-*s  %*lld %s %s\n", print_info.filetype, print_info.permission,
		print_info.acl_xattr, align.max_num_link, print_info.num_link, align.max_len_user, print_info.user, align.max_len_group, print_info.group,
		align.max_num_size_file, print_info.size_file, print_info.date, print_info.filename);
		beg = beg->next;
	}
}
