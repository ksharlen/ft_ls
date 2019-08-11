#include "ft_ls.h"

int		main(int argc, char **argv)
{
	DIR *dir;

	opendir("bin");
	ft_ls(argc, argv);
	return (0);
}
