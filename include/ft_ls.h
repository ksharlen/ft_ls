/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:19:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/12 13:29:45 by ksharlen         ###   ########.fr       */
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
# define ESTATE_EACCESS				EACCESS
# define ESTATE_ENOMEM				ENOMEM
# define ESTATE_ENAMETOOLONG		ENAMETOOLONG



# define NUM_FLAGS		53
# define FLAGS			"adfglrtuR"
# define FLAG_ON		1
# define FLAG_OFF		0
# define FLAG_LOW_REG(x) ((x) >= 'a' && (x) <= 'z' ? 1 : 0)
# define FLAG_UPP_REG(x) ((x) >= 'A' && (x) <= 'Z' ? 1 : 0)
# define FLAG_VALID(x) ((FLAG_LOW_REG(x) || FLAG_UPP_REG(x) ? 1 : 0))

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

//*Отсортировать по размеру для экономии места
typedef struct			s_ls
{
	struct stat			*buf;
	struct s_ls			*next;
	char				*name;
	char				*pw_name;
	char				*gr_name;
	//*Тут будут еще расширенные атрибуты;
	//*Подумать про указатель на предыдущий элемент
}						t_ls;

typedef struct			s_filename
{
	t_ls				*full_descript;
	struct s_filename	*next;
	char				*filename;
}						t_filename;

int						ft_ls(size_t argc, char *const argv[]);
int						list_push_files(t_ls **beg, size_t argc, char *const argv[]);
//*int						list_push_filename(t_filename **beg, int argc, char *const argv[]);
int						get_options(const char *options, t_ubyte *flags);
size_t					list_filename_size(t_filename *beg);
void					list_filename_add_end(t_filename **beg, char *filename);
void					valid_flags(const t_ubyte *flags);

#endif
