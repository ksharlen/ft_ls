/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:00:57 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/12 20:20:41 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define FT_CAT(x, y) x#y

#define FT_TEST(x) ++(x);
#define TEST(x) while (x > 0) FT_TEST(x);
#define STRING	"ls: illegal option -- z\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n"

static void print_arr(int *num, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("num[%ld] = %d\n", i, num[i]);
		++i;
	}
}

static char *read_all_files_from_dir(DIR	*dir)
{
	register size_t	i;
	struct dirent	*dent;

	while ((dent = readdir(dir)))
	{
		write(1, dent->d_name, ft_strlen(dent->d_name));
		write(1, " ", 1);
	}
	//printf("errno: %d\n", errno);
	perror("ls");
}

int		main(int argc, char **argv)
{
	DIR		*dir;
	dir = opendir(argv[1]);
	if (dir)
		read_all_files_from_dir(dir);
	else if (errno == 20)
	{
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, "\n", 1);
		//printf("errno: %d\n", errno);
		//perror("ls");
	}
	return (0);
}
