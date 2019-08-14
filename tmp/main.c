/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:00:57 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/14 12:37:54 by ksharlen         ###   ########.fr       */
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
#include <uuid/uuid.h>

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

int		main(int argc, char **argv)
{
	// if (argc == 2)
	// 	_val_diropen_(argv[1]);
	// else if (argc == 1)
	// 	_val_diropen_(".");
	// return (0);
	// DIR	*dir;
	// struct dirent *dent;

	// dir = opendir(argv[1]);
	// if (dir)
	// 	while ((dent = readdir(dir)))
	// 	{
	// 		if (!strcmp(dent->d_name, ".") || !strcmp(dent->d_name, ".."))
	// 			;
	// 		else
	// 			ft_printf("%s -- %d\n", dent->d_name, dent->d_type);
	// 	}
	// else
	// 	printf("error\n");
	perror(strerror(ENAMETOOLONG));
	return (0);
}
