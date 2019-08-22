#include "ft_ls.h"

static void	fill_s_print(const t_filename *beg, const t_ubyte *flags, struct s_print *info)
{
	info->filetype = pull_filetype(beg->f_type);
	info->permission = pull_access_permission(beg->buf->st_mode);
	info->acl_xattr = pull_acl_xattr(beg->path);
	info->num_link = beg->buf->st_nlink;
	info->user = beg->pw_name;
	if (flags[FIND_FLAG('g')])
		info->group = beg->gr_name;
	else
		info->group = "";
	info->date = pull_date(beg, flags);
}

void	print_fullinfo(const t_filename *beg, const t_ubyte *flags)
{
	struct s_print	print_info;
	struct s_num	align;

	P_UNUSED(print_info);
	P_UNUSED(align);
	P_UNUSED(flags);
	//тут будет определение выравнивания
	max_len_elem(beg, &align);
	printf("total %lld\n", align.total);
	while (beg)
	{
		fill_s_print(beg, flags, &print_info);
		//printf("%c%s%c  %*d %*s %*s  %*lld %s %*s\n");
		beg = beg->next;
	}
}
