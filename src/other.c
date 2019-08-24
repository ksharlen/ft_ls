#include "ft_ls.h"

const char	*cut_date(const time_t sec)
{
	const char *s_time;
	const char *ret_date;

	s_time = ctime(&sec);
	ret_date = ft_strsub(s_time, 4, 12);
	if (!ret_date)
		sys_errors();
	return (ret_date);
}
//?Переделать
void	max_len_elem(const t_filename *beg, struct s_num *align)
{
	int		cmp;

	align->max_len_user = 0;
	align->max_len_group = 0;
	align->max_num_link = 0;
	align->max_num_size_file = 0;
	align->total = 0;
	while (beg)
	{
		align->total += beg->buf->st_blocks;
		cmp = ft_strlen(beg->pw_name);
		if (cmp > align->max_len_user)
			align->max_len_user = cmp;
		cmp = ft_strlen(beg->gr_name);
		if (cmp > align->max_len_group)
			align->max_len_group = cmp;
		cmp = ft_size_num(beg->buf->st_nlink);
		if (cmp > align->max_num_link)
			align->max_num_link = cmp;
		cmp = ft_size_num(beg->buf->st_size);
		if (cmp > align->max_num_size_file)
			align->max_num_size_file = cmp;
		beg = beg->next;
	}
	//printf("u: %d\ng: %d\nl: %d\ns: %d\n", align->max_len_user, align->max_len_group, align->max_num_link, align->max_num_size_file);
	//printf("total %lld\n", align->total);
}

// void	max_weight(t_filename *beg, struct s_num *align)
// {
// 	int	num_cap;
// //?Переписать эту ф-ию
// 	align->max_len_group = 0;
// 	align->max_len_user = 0;
// 	align->max_num_link = 0;
// 	align->max_num_size_file = 0;
// 	while (beg)
// 	{
// 		beg->info->pw_name = getpwuid(beg->info->buf.st_uid)->pw_name;
// 		beg->info->gr_name = getgrgid(beg->info->buf.st_gid)->gr_name;
// 		num_cap = (int)ft_strlen(beg->info->pw_name);
// 		if (num_cap > align->max_len_user)
// 			align->max_len_user = num_cap;
// 		num_cap = (int)ft_strlen(beg->info->gr_name);
// 		if (num_cap > align->max_len_group)
// 			align->max_len_group = num_cap;
// 		num_cap = (int)ft_size_num(beg->info->buf.st_nlink);
// 		if (num_cap > align->max_num_link)
// 			align->max_num_link = num_cap;
// 		num_cap = (int)ft_size_num(beg->info->buf.st_size);
// 		if (num_cap > align->max_num_size_file)
// 			align->max_num_size_file = num_cap;
// 		beg = beg->next;
// 	}
// }

// int		max_weight(const t_filename *beg, int (*cmp)(int, constt_filename *))
// {
// 	int	max_num;

// 	max_num = 0;
// 	while (beg)
// 	{
// 		max_num = cmp(max_num, beg);
// 		beg = beg->next;
// 	}
// 	return (max_num);
// }

char	*cat_path_filename(const char *dirname, const char *filename)
{
	size_t	size_ret;
	size_t	size_dirname;
	char *ret;
	int8_t	separator;

	separator = 1;
	size_dirname = ft_strlen(dirname);
	size_ret = size_dirname + ft_strlen(filename);
	ret = ft_strnew(size_ret + separator);
	ft_strcpy(ret, dirname);
	if (dirname[size_dirname - 1] != '/')
		ft_strcat(ret, "/");
	ft_strcat(ret, filename);
	return (ret);
}

void	push_permission_o(mode_t st_mode, char *str)
{
	if (st_mode & O_R)
		*str = 'r';
	else
		*str = '-';
	++str;
	if (st_mode & O_W)
		*str = 'w';
	else
		*str = '-';
	++str;
	if (st_mode & O_T)
		*str = 't';
	else if (st_mode & O_X)
		*str = 'x';
	else if (st_mode & O_XX)
		*str = 'X';
	else if (st_mode & O_S)
		*str = 's';
	else
		*str = '-';
}

void	push_permission_ug(uint16_t r, uint16_t w, uint16_t x, char *str)
{
    if (!r)
        *str = '-';
    else
        *str = 'r';
    ++str;
    if (!w)
        *str = '-';
    else
        *str = 'w';
    ++str;
    if (!x)
        *str = '-';
    else
        *str = 'x';
}