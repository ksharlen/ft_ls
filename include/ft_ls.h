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

# define NUM_FLAGS		53
# define FLAGS			"adfglrtuR"
# define FLAG_ON		1
# define FLAG_OFF		0
# define FLAG
# define FLAG_LOW_REG(x) ((x) >= 'a' && (x) <= 'z' ? 1 : 0)
# define FLAG_UPP_REG(x) ((x) >= 'A' && (x) <= 'Z' ? 1 : 0)
# define FLAG_VALID(x) ((FLAG_LOW_REG(x) || FLAG_UPP_REG(x) ? 1 : 0))

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
//int		list_push_filename(t_filename **beg, int argc, char *const argv[]);
int		get_options(const char *options, l_utype *flags);
size_t	list_filename_size(t_filename *beg);
void	list_filename_add_end(t_filename **beg, char *filename);
void	valid_flags(const l_utype *flags);

#endif
