#include "ft_ls.h"

char	pull_acl_xattr(const char *path)
{
	ssize_t	xattr;
	acl_t	acl;
	acl_type_t type;
	size_t option;
	char	ret;

	option = XATTR_NOFOLLOW;
	type = ACL_TYPE_EXTENDED;
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
	return (ret);
}

char    *pull_access_permission(const t_filename *beg)
{
    size_t          size_permission;
    char            *return_str;
    char            *p_run;

    size_permission = 9;
    return_str = (char *)ft_memalloc(sizeof(char) * (size_permission + 1));
    p_run = return_str;
    return_str[size_permission] = '\0';
    push_permission_ug(beg->buf->st_mode & U_R, beg->buf->st_mode & U_W, beg->buf->st_mode & U_X, p_run);
    p_run += 3;
    push_permission_ug(beg->buf->st_mode & G_R, beg->buf->st_mode & G_W, beg->buf->st_mode & G_X, p_run);
    p_run += 3;
    push_permission_o(beg->buf->st_mode, p_run);
    return (return_str);
}

char    pull_filetype(const t_filename *beg)
{
    char filetype;

    if (beg->f_type == U_TYPE)
        filetype = 'u';
    else if (beg->f_type == F_TYPE)
        filetype = 'f';
    else if (beg->f_type == C_TYPE)
        filetype = 'c';
    else if (beg->f_type == D_TYPE)
        filetype = 'd';
    else if (beg->f_type == B_TYPE)
        filetype = 'b';
    else if (beg->f_type == R_TYPE)
        filetype = '-';
    else if (beg->f_type == L_TYPE)
        filetype = 'l';
    else if (beg->f_type == S_TYPE)
        filetype = 's';
    else if (beg->f_type == W_TYPE)
        filetype = 'w';
    else
        filetype = '-';
    return (filetype);
}