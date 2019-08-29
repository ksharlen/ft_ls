#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
// #include "libft.h"


//STDOUT_FILENO

int		main(void)
{
	char *p;
	char *test;
	const char *string = "hello world";
	char color[10] = "\e[;36;1m";

	// err = ioctl(STDOUT_FILENO, TIOCGWINSZ, &wins);
	// printf("r: %d\nc: %d\nx: %d\ny: %d\n", wins.ws_row, wins.ws_col, wins.ws_xpixel, wins.ws_ypixel);
	//printf("%s\n", LSCOLORS);
	// if (p = getenv("LSCOLORS") || !*p)
	// printf("%d\n", p[9]);
	// printf("p: %s\n", p);
	// if ((p = getenv("LSCOLORS")))
	// {
	// 	if (p[0] == 'G')
	// 		strcat(color, "{/blue}");
	// }
	//printf("\e[;33mtesting\n");
	//ft_printf("%s%s\n", color, string);
	test = "{/blue}";
	printf("%sa.out.dSYM", color);
	return (0);
}