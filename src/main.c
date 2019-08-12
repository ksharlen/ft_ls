#include "ft_ls.h"

int		main(int argc, char **argv)
{
	size_t	u_argc;

	u_argc = (size_t)argc;
	printf("%s\n", strerror(ENOENT));
	
	ft_ls(u_argc, argv);
	return (0);
}
