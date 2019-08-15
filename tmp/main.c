/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:00:57 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/15 14:13:51 by ksharlen         ###   ########.fr       */
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

static void	merge_sort(int	*num, size_t size)
{
	register size_t i;
	register size_t j;
	register size_t k;
	int *left;
	int	*right;
	int main_arr[size];

	ft_bzero(main_arr, size);
	//main_arr = (int[size]){0};
	if (size == 1)
		return ;
	merge_sort(num, size / 2);
	left = num;
	right = num + (size / 2);
	i = 0;
	k = 0;
	j = size / 2;
	//printf("here\n");
	while (i < (size / 2) || j < (size / 2))
		main_arr[k++] = (left[i] >= right[j] ? right[j++] : left[i++]);
	if (j == (size / 2))
	{
		while (i < (size / 2))
			main_arr[k++] = left[i++];
	}
	else if (i == (size / 2))
	{
		while (j < (size / 2))
			main_arr[k++] = right[j++];
	}
	printf("main_arr: \n");
	print_num(main_arr, size);
	printf("==================\n");
}

int		main(int argc, char **argv)
{
	int		num[SIZE] = { 31, 23 ,4242, 31, 23232, 42, 32323, 41 };
	printf("BEFORE:\n");
	print_num(num, SIZE);
	merge_sort(num, SIZE);
	printf("AFTER:\n");
	print_num(num, SIZE);
	return (0);
}