#include "ft_ls.h"

void	max_weight(const t_filename *beg, int *max_link, int *max_num_size_file)
{
	int	num_cap;

	*max_link = 0;
	*max_num_size_file = 0;
	while (beg)
	{
		num_cap = ft_size_num(beg->info->buf.st_nlink);
		if (*max_link < num_cap)
			*max_link = num_cap;
		num_cap = ft_size_num(beg->info->buf.st_size);
		if (*max_num_size_file < num_cap)
			*max_num_size_file = num_cap;
		beg = beg->next;
	}
}

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