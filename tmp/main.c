/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:00:57 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/17 13:07:15 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define SIZE 8

static void		_val_diropen_(char *filename)
{
	DIR *dir;
	struct dirent *dent;

	dir = opendir(filename);
	if (!dir)
		perror("ls :");
	else
	{
		printf("%s:\n", filename);
		while ((dent = readdir(dir)))
		{
			if (!strcmp(dent->d_name, ".") || !strcmp(dent->d_name, ".."))
				;
			else
			{
				printf("%s\n", dent->d_name);
				strcat(filename, "/");
				strcat(filename, dent->d_name);
				_val_diropen_(filename);
			}
		}
	}
}

static void	print_num(int *num, size_t size)
{
	register size_t i;

	i = 0;
	while (i < size)
	{
		printf("num[%ld] = %d\n", i, num[i]);
		++i;
	}
}

int		main(int argc, char **argv)
{
	DIR	*dir;
	struct dient *dent;
	struct stat buf;
	char *t_time;

	//dir = opendir(argv[1]);
	//dent = readdir(dir);
	stat(argv[1], &buf);
	t_time = ctime(buf.st_atime);
	printf("buf->atime: %s\n", t_time);
	return (0);
}
