#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR				*fd;
	struct dirent	*list;
	struct stat		buf;
	int				err;
	struct passwd	*pwd;
	struct group	*grp;

	ssize_t			list_ret;
	const char		*path;
	char			*buf_listxattr;
	size_t			size;
	int				opt;

	char *a;
	char *m;
	char *c;

	opt = 0;
	size = 1000;
	path = "/Users/ksharlen/Library";
	buf_listxattr = (char *)ft_memalloc(sizeof(char) * size);
	if (!buf_listxattr)
		exit(0);
	// list_ret = listxattr(path, buf_listxattr, size, 0);
	// ft_printf("buf_listxattr: %s\n", buf_listxattr);
	// ft_printf("list_ret = %ld\n", list_ret);

	list_ret = getxattr("/Usert/ksharlen/Library", "com", buf_listxattr, size, 0, 0);
	ft_printf("getxattr:\n");

	ft_printf("getxattr: %s\n", buf_listxattr);
	ft_printf("list_ret = %ld\n", list_ret);
	//buf = (struct stat *)ft_memalloc(sizeof(struct stat));
	// err = stat("Makefile", &buf);
	// // ft_printf("err = %d\n", err);
	// ft_printf("st_uid: %u\n", buf.st_uid);
	// pwd = getpwuid(buf.st_uid);
	// ft_printf("pw_user:		%s\n", pwd->pw_name);
	// ft_printf("pw_password: %s\n", pwd->pw_passwd);
	// ft_printf("pw_uid:		%u\n", pwd->pw_uid);
	// ft_printf("pw_gid:		%u\n", pwd->pw_gid);
	// ft_printf("pw_gecos:	%s\n", pwd->pw_gecos);
	// ft_printf("pw_dir:		%s\n", pwd->pw_dir);
	// ft_printf("pw.shell:	%s\n", pwd->pw_shell);
	// grp = getgrgid(buf.st_gid);
	// ft_printf("gr_name: %s\n", grp->gr_name);
	// ft_printf("gr_passwd: %s\n", grp->gr_passwd);
	// ft_printf("gr_id: %u\n", grp->gr_gid);
	// printf("err = %d\n", err);
	// ft_printf("st_dev = %u | st_ino = %u | st_mode = %u | st_inlink = %u | st_uid = %u | st_gid = %u | st_rdev = %u | st_size = %u | st_blksize = %u | st_blocks = %u\n",
	// buf.st_dev, buf.st_ino, buf.st_mode, buf.st_nlink, buf.st_uid, buf.st_gid, buf.st_rdev, buf.st_size, buf.st_blksize, buf.st_blocks);
	// ft_printf("time: %s", ctime(&buf.st_atime));
	// a = ctime(&buf.st_atime);
	// m = ctime(&buf.st_mtime);
	// c = ctime(&buf.st_ctime);
	// ft_printf("st_atime: %s\nst_mtime: %s\nst_ctime: %s\n", a, m, c);
	return (0);
}
