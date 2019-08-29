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
}

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
