#include "ft_ls.h"

const char *pull_date(const t_filename *beg, const t_ubyte *flags)
{
	const char *ret_date;

	ret_date = NULL;
	if (flags[FIND_FLAG('t')])
	{
		if (flags[FIND_FLAG('u')])
			ret_date = cut_date(beg->buf->st_atimespec.tv_sec);
		else
			ret_date = cut_date(beg->buf->st_mtimespec.tv_sec);
	}
	else if (flags[FIND_FLAG('u')])
		ret_date = cut_date(beg->buf->st_atimespec.tv_sec);
	else
		ret_date = cut_date(beg->buf->st_ctimespec.tv_sec);
	return (ret_date);
}

char	pull_acl_xattr(const char *path)
{
	ssize_t	xattr;
	acl_t	acl;
	acl_type_t type;
	size_t option;
	char	ret;

	option = XATTR_NOFOLLOW;
	type = ACL_TYPE_EXTENDED;
	xattr = listxattr(path, NULL, 0, option);
	if (xattr < 0)
		xattr = 0;
	acl = acl_get_file(path, type);
	if (xattr > 0)
		ret = '@';
	else if (acl != NULL)
		ret = '+';
	else
		ret = ' ';
	acl_free(acl);
	return (ret);
}

char    pull_filetype(const int8_t int_ftype)
{
    char filetype;

    if (int_ftype == U_TYPE)
        filetype = 'u';
    else if (int_ftype == F_TYPE)
        filetype = 'f';
    else if (int_ftype == C_TYPE)
        filetype = 'c';
    else if (int_ftype == D_TYPE)
        filetype = 'd';
    else if (int_ftype == B_TYPE)
        filetype = 'b';
    else if (int_ftype == R_TYPE)
        filetype = '-';
    else if (int_ftype == L_TYPE)
        filetype = 'l';
    else if (int_ftype == S_TYPE)
        filetype = 's';
    else if (int_ftype == W_TYPE)
        filetype = 'w';
    else
        filetype = '-';
    return (filetype);
}

const char *pull_val_link(const char *path_link)
{
	char *filename_from_link;
	char *print_link;

	filename_from_link = valid_readlink(path_link);
	if (filename_from_link)
	{
		print_link = ft_strjoin(" -> ", filename_from_link);
		CHECK_ALLOC(filename_from_link);
	}
	else
		print_link = NULL;
	ft_strdel((char **)&filename_from_link);
	return (print_link);
}