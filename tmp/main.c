/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:00:57 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/12 15:49:26 by ksharlen         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	//int	arr[5];// = {0};
	// int		*arr;
	// int		i = 0;

	char *str1 = "hello";
	char *str2 = " world";

	// arr = (int[15]){ [3] = 6 };
	// arr = (int[7]){ [2] = 10 };
	// printf("arr[9] = %d\n", arr[17]);
	//print_arr(arr, 15);
	DIR				*dir;
	struct dirent	*dirent;
	char			*filename;
	char			*str;

	// filename = argv[1];
	// dir = opendir(filename);
	// if (dir)
	// 	printf("success\n");
	// else
	// 	perror(ft_strjoin("ls: ", filename));
	// printf("dir: %x\n", dir);
	//printf("%s\n", FT_CAT(str1, str2));
	write(2, STRING, strlen(STRING));
	return (0);
}
