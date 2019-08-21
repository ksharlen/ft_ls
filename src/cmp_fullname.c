#include "ft_ls.h"

#if __linux__

static const unsigned char *skip_not_alpha(const unsigned char *str)
{
	if (*str)
	{
		while (*str && !ft_isalnum(*str))
			++str;
	}
	return (str);
}

static int	ls_strcasecmp(const char *s1, const char *s2)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	int	result;

	result = 0;
	while (*p1 && *p2)
	{
		if (!ft_isalnum(*p1))
			p1 = skip_not_alpha(p1);
		if (!ft_isalnum(*p2))
			p2 = skip_not_alpha(p2);
		if ((ft_tolower(*p1) != ft_tolower(*p2)))
			break ;
		else
		{
			++p1;
			++p2;
		}
	}
	result = ft_tolower(*p1) - ft_tolower(*p2);
	return (result);
	// while ((result = ft_lower(*p1) - ft_tolower(*p2++)) == 0)
	// {
	// 	if ()
	// }
}

int		cmp_atime(t_filename *one, t_filename *two)
{
	if (one->info->buf.st_atime > two->info->buf.st_atime)
		return (TRUE);
	else
		return (FALSE);
}

int		cmp_mtime(t_filename *one, t_filename *two)
{
	if (one->info->buf.st_mtime > two->info->buf.st_mtime)
		return (TRUE);
	else
		return (FALSE);
}

int		cmp_name(t_filename *one, t_filename *two)
{
	if (ft_strcmp(one->filename, two->filename) < 0)
		return (TRUE);
	else
		return (FALSE);
}

#endif

#if __APPLE__

int		cmp_atime(t_filename *one, t_filename *two)
{
	if (one->info->buf.st_atimespec.tv_sec > two->info->buf.st_atimespec.tv_sec)
		return (TRUE);
	else
		return (FALSE);
}

int		cmp_mtime(t_filename *one, t_filename *two)
{
	if (one->info->buf.st_mtimespec.tv_sec > two->info->buf.st_mtimespec.tv_sec)
		return (TRUE);
	else
		return (FALSE);
}

int		cmp_name(t_filename *one, t_filename *two)
{
	if (ft_strcmp(one->filename, two->filename) < 0)
		return (TRUE);
	else
		return (FALSE);
}

#endif