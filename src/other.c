#include "ft_ls.h"

char	*cat_path_filename(const char *dirname, const char *filename)
{
	size_t	size_ret;
	char *ret;
	int8_t	separator;

	separator = 1;
	size_ret = ft_strlen(dirname) + ft_strlen(filename);
	ret = ft_strnew(size_ret + separator);
	ft_strcpy(ret, dirname);
	ft_strcat(ret, "/");
	ft_strcat(ret, filename);
	//ft_printf("dirname: %s\nfilename: %s\n", dirname, filename);
	return (ret);
}