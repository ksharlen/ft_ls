#include "ft_ls.h"

//*СДЕЛАТЬ РЕФАКТ!!!

static void	fill_s_print(const t_filename *beg, const t_ubyte *flags, struct s_print *info)
{
	if (info->ls_color)
		info->color = push_color(beg->buf->st_mode, info->ls_color);
	info->filetype = pull_filetype(beg->f_type);
	info->permission = pull_access_permission(beg->buf->st_mode);
	info->acl_xattr = pull_acl_xattr(beg->path);
	info->num_link = beg->buf->st_nlink;
	info->group = beg->gr_name;
	if (flags[FIND_FLAG('g')])
	{
		info->user = info->group;
		info->group = "";
	}
	else
		info->user = beg->pw_name;
	info->size_file = beg->buf->st_size;
	info->date = pull_date(beg, flags);
	info->filename = beg->filename;
	//!info->date need free
}

void	print_fullinfo(const t_filename *beg, const t_ubyte *flags, const char *ls_color)
{
	struct s_print	print_info;
	struct s_num	align;

	//тут будет определение выравнивания
	print_info.ls_color = ls_color;
	max_len_elem(beg, &align);
	align.max_len_group += 2;
	align.max_num_size_file += 2;
	if (flags[FIND_FLAG('g')])
	{
		align.max_len_user = align.max_len_group - 2;
		align.max_len_group = 0;
	}
	// printf("sf: %d\n", align.max_num_size_file);
	// exit(EXIT_SUCCESS);
	printf("total %lld\n", align.total);
	while (beg)
	{
		fill_s_print(beg, flags, &print_info);
		printf("%c%s%c %*d %-*s%-*s%*lld %s %s%s%s\n", print_info.filetype, print_info.permission, //%s - цвет и ширина, %s имя файла %s - файл ссылки
		print_info.acl_xattr, align.max_num_link, print_info.num_link, align.max_len_user, print_info.user, align.max_len_group, print_info.group,
		align.max_num_size_file, print_info.size_file, print_info.date, print_info.color, print_info.filename, DEFAULT_STYLE);
		beg = beg->next;
	}
}
