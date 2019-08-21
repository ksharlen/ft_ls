/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:19:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/20 14:27:24 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/xattr.h>
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>

/*
**ERRORS
*/
# define EOPENDIR_EACCES			EACCES
# define EOPENDIR_EMFILE			EMFILE
# define EOPENDIR_ENFILE			ENFILE
# define EOPENDIR_ENOENT			ENOENT
# define EOPENDIR_ENOMEM			ENOMEM
# define EOPENDIR_ENOTDIR			ENOTDIR

# define ECLOSEDIR_EBADF			EBADF

# define EREADDIR_ENBADF			EBADF
//!
# define EGETPWUID_ENOENT			ENOENT
# define EGETPWUID_ESRCH			ESRCH
# define EGETPWUID_EBADF			EBADF
# define EGETPWUID_EPERM			EPERM
# define EGETPWUID_ENOMEM			ENOMEM
# define EGETPWUID_EIO				EIO
# define EGETPWUID_EINTR			EINTR
# define EGETPWUID_EMFILE			EMFILE
# define EGETPWUID_ENFILE			ENFILE

# define EGETGRGID_ENOENT			ENOENT
# define EGETGRGID_ESRCH			ESRCH
# define EGETGRGID_EBADF			EBADF
# define EGETGRGID_EPERM			EPERM
# define EGETGRGID_ENOMEM			ENOMEM
# define EGETGRGID_EIO				EIO
# define EGETGRGID_EINTR			EINTR
# define EGETGRGID_EMFILE			EMFILE
# define EGETGRGID_ENFILE			ENFILE
//!
# define ELISRXATTR_ENOTSUP			ENOTSUP
# define ELISRXATTR_ERANGE			ERANGE
# define ELISRXATTR_EPERM			EPERM
# define ELISRXATTR_ENOTDIR			ENOTDIR
# define ELISRXATTR_ENAMETOOLONG	ENAMETOOLONG
# define ELISRXATTR_EACCES			EACCES
# define ELISRXATTR_ELOOP			ELOOP
# define ELISRXATTR_EFAULT			EFAULT
# define ELISRXATTR_EIO				EIO
# define ELISRXATTR_EINVAL			EINVAL

# define EGETXATTR_ENOATTR			ENOATTR
# define EGETXATTR_ENOTSUP			ENOTSUP
# define EGETXATTR_ERANGE			ERANGE
# define EGETXATTR_EPRERM			EPERM
# define EGETXATTR_EINVAL			EINVAL
# define EGETXATTR_EISDIR			EISDIR
# define EGETXATTR_ENOTDIR			ENOTDIR
# define EGETXATTR_ENAMETOOLONG		ENAMETOOLONG
# define EGETXATTR_EACCES			EACCES
# define EGETXATTR_ELOOP			ELOOP
# define EGETXATTR_EFAULT			EFAULT
# define EGETXATTR_EIO				EIO

# define ESTATE_EBADF 				EBADF
# define ESTATE_ENOENT 				ENOENT
# define ESTATE_ENOTDIR				ENOTDIR
# define ESTATE_ELOOP				ELOOP
# define ESTATE_EFAULT				EFAULT
# define ESTATE_EACCES				EACCES
# define ESTATE_ENOMEM				ENOMEM
# define ESTATE_ENAMETOOLONG		ENAMETOOLONG

# define U_TYPE						DT_UNKNOWN
# define F_TYPE						DT_FIFO
# define C_TYPE						DT_CHR
# define D_TYPE						DT_DIR
# define B_TYPE						DT_BLK
# define R_TYPE						DT_REG
# define L_TYPE						DT_LNK
# define S_TYPE						DT_SOCK
# define W_TYPE						DT_WHT

# define EFLAGS	"usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n"
//# define EPERM	"ls: %s: Permission denied\n" //%s dirname
# define FILE_ERROR(filename)	ft_printf("%vls: %s: ", 2, filename)

# define NUM_FLAGS		53
# define FLAGS			"adfglrtuR"
# define FLAG_ON		1
# define FLAG_OFF		0
# define FLAG_LOW_REG(x) ((x) >= 'a' && (x) <= 'z' ? 1 : 0)
# define FLAG_UPP_REG(x) ((x) >= 'A' && (x) <= 'Z' ? 1 : 0)
# define FLAG_VALID(x) ((FLAG_LOW_REG(x) || FLAG_UPP_REG(x) ? 1 : 0))
# define CHECK_KEY(x) ((*(x) == '-') && (*(x + 1) != 0) ? 1 : 0)
# define GET_FLAG(flag) ((flag) >= 'a' && ((flag) <= 'z') ? ('a' - 1) : 38)
# define FIND_FLAG(flag) ((flag) - GET_FLAG(flag))

#define	P_UNUSED(variable) ((void)variable)

# define CURRENT_DIR "."

//?Прежде чем вызвать ft_strlen проверяет не пустая ли строка, если пустая, вызова не происходит

typedef	int8_t			t_byte;
typedef uint8_t			t_ubyte;

# define BYTE	t_byte;
# define UBYTE 	t_ubyte;

typedef enum
{
						FAILD_COMPLETION = -1,
						SUCCESSFUL_COMPLETION
}						t_return;

typedef enum
{
						FALSE,
						TRUE
}						t_bool;

//*Отсортировать по размеру для экономии места
typedef struct			s_fullinfo
{
	struct stat			buf;
	const unsigned char	*pw_name;
	const char			*gr_name;
}						t_fullinfo;

typedef struct			s_filename
{
	struct s_filename	*next;
	t_fullinfo			*info;
	const char 			*filename;
	char				*dirname;
	uint8_t				f_type;
}						t_filename;

int						ft_ls(size_t argc, char *const argv[]);

/*
**Lists filename
*/
size_t					list_filename_size(t_filename *beg);
void					list_filename_add_end(t_filename **beg, const char *filename, uint8_t f_type);
void					push_list_filename_dir_content(DIR *dir, t_filename **beg, t_ubyte *flags);

/*
**Lists fullinfo
*/
void					push_fullinfo_to_filename(t_filename *beg, const char *dirname, t_ubyte *flags);

/*
**Validation
*/
void					valid_flags(const t_ubyte *flags);
DIR						*valid_opendir(const char *filename);
struct dirent			*valid_readdir(DIR *dir);
int						valid_stat(const char *filename, struct stat *buf);

/*
**Errors
*/
void					sys_errors(void);
void					file_errors(const char *filename);

/*
**Sorts
*/
t_filename				*sort_list_by_flags(t_filename **beg, t_ubyte *flags);
t_filename				*list_filename_merge(t_filename *l_one, t_filename *l_two, int (*key)(t_filename *, t_filename *));

/*
**Other
*/
int						chk_flags_for_create_fullinfo(t_ubyte *flags);
int						chk_flags_for_print_fullinfo(t_ubyte *flags);
int						get_options(const char *options, t_ubyte *flags);
void					list_revers(t_filename **beg);

/*
**Compare
*/
int						cmp_atime(t_filename *one, t_filename *two);
int						cmp_mtime(t_filename *one, t_filename *two);
int						cmp_name(t_filename *one, t_filename *two);

/*
**print_list
*/
void					print_list(t_filename *beg, t_ubyte *flags);
void					print_fullinfo(const t_filename *beg, const t_ubyte *flags);

#endif
