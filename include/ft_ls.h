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

# define NUM_FLAGS	10

typedef	char			l_type;
typedef unsigned char	l_utype;

typedef struct	s_ls
{
	char		*name;
	struct stat	*buf;
	char		*pw_name;
	char		*gr_name;
	struct s_ls	*next;
	//Тут будут еще расширенные атрибуты;
	//Подумать про указатель на предыдущий элемент
}				t_ls;

typedef struct			s_filename
{
	char				*filename;
	t_ls				*full_descript;
	struct s_filename	*next;
}						t_filename;

int		ft_ls(int argc, char *const argv[]);
int		list_push_files(t_ls **beg, int argc, char *const argv[]);
int		list_push_filename(t_filename **beg, int argc, char *const argv[]);

#endif
