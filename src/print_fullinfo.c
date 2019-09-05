#include "ft_ls.h"

//*СДЕЛАТЬ РЕФАКТ!!!

static void clean_mem(struct s_print print_info)
{
	ft_strdel((char **)&print_info.color);
	ft_strdel((char **)&print_info.date);
	ft_strdel((char **)&print_info.permission);
	if (*print_info.val_link)
	{
		printf("1\n");
		ft_strdel((char **)&print_info.color);
	}
}

static void	fill_s_print(const t_filename *beg, const t_ubyte *flags, struct s_print *info)
{
	if (info->ls_color)
		info->color = push_color(beg->buf->st_mode, info->ls_color);
	info->filetype = pull_filetype(beg->f_type);
	if (S_ISLNK(beg->buf->st_mode))
		info->val_link = pull_val_link(beg->path);
	else
		info->val_link = "";
		//info->val_link = valid_readlink(beg->path);
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

	print_info.ls_color = ls_color;
	max_len_elem(beg, &align);
	align.max_len_user += 2;
	align.max_len_group += 2;
	if (flags[FIND_FLAG('g')])
	{
		align.max_len_user = align.max_len_group;
		align.max_len_group = 0;
	}
	ft_printf("total %lld\n", align.total);
	while (beg)
	{
		fill_s_print(beg, flags, &print_info);
		ft_printf("%c%s%c %*d %-*s%-*s%*lld %s %s%s%s%s\n", print_info.filetype, print_info.permission, //%s - цвет и ширина, %s имя файла %s - файл ссылки
		print_info.acl_xattr, align.max_num_link, print_info.num_link, align.max_len_user, print_info.user, align.max_len_group, print_info.group,
		align.max_num_size_file, print_info.size_file, print_info.date, print_info.color, print_info.filename, DEFAULT_STYLE, print_info.val_link);
		beg = beg->next;
		clean_mem(print_info);
	}
}
