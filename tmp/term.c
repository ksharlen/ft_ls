#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//STDOUT_FILENO

int		main(void)
{
	int err;
	int fd;
	struct winsize wins;

	err = ioctl(STDOUT_FILENO, TIOCGWINSZ, &wins);
	printf("r: %d\nc: %d\nx: %d\ny: %d\n", wins.ws_row, wins.ws_col, wins.ws_xpixel, wins.ws_ypixel);
	return (0);
}