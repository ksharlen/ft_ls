#include "ft_ls.h"

static t_ls	*list_create(void)
{
	t_ls	*new;

	new = (t_ls *)ft_memalloc(sizeof(t_ls));
	if (!new)
		exit(0); //Тут будем думать
	new->name = NULL;
	new->buf = NULL;
	new->pw_name = NULL;
	new->gr_name = NULL;
	new->next = NULL;
	return (new);
}

static int		init_file(t_ls *elem, DIR *dir)
{
	struct dirent	*file;
	struct passwd	*pwd;

	file = readdir(dir);//Тут может быть ошибка
	elem->name = file->d_name;
	stat(elem->name, elem->buf);//Тут может быть ошибка
	errno = 0;
	pwd = (struct passwd *)ft_memalloc(sizeof(struct passwd));
	printf("file_name: %s", elem->name);
	//Учесть файлы с точкой
	//pwd = getpwuid(elem->buf->st_gid);
	//printf("errno: %d\n", errno);
	elem->pw_name = pwd->pw_name;
}

int		list_push_files(t_ls **beg, int argc, char *const argv[])
{
	register size_t i;
	DIR				*dir;
	t_ls			*elem;

	i = 1;
	while (i < argc)
	{
		elem = list_create();
		dir = opendir(argv[i]);
		init_file(elem, dir);
		++i;
	}
}
