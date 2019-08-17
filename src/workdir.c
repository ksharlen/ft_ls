/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:48:19 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/17 20:07:45 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR		*valid_opendir(const char *filename)
{
	DIR	*dir;

	errno = 0;
	dir = opendir(filename);
	if (errno == EOPENDIR_EACCES)
	{
		file_errors(filename);
		printf("here\n");
	}
	else if (errno == EOPENDIR_ENOENT)
	{
		file_errors(filename);
		ft_printf("%venoent:\n", 2);
	}
	else if (errno == EOPENDIR_EMFILE)
		sys_errors();
	else if (errno == EOPENDIR_ENFILE)
		sys_errors();
	else if (errno == EOPENDIR_ENOMEM)
		sys_errors();
	else if (errno == EOPENDIR_ENOTDIR)
	{
		//файл не директория, но ее все равно нужно вывести на экран
	}
	else
		return (dir);
	return (NULL);
}

struct dirent *valid_readdir(DIR *dir)
{
	struct dirent *dent;

	dent = readdir(dir);
	if (errno == EREADDIR_ENBADF)
		sys_errors();
	return (dent);
}

int		valid_stat(const char *filename, struct stat *buf)
{
	errno = 0;
	stat(filename, buf);
	if (errno == ESTATE_EACCES)
		file_errors(filename);
	else if (errno == ESTATE_EBADF)
		file_errors(filename);
	else if (errno == ESTATE_EFAULT)
		sys_errors();
	else if (errno == ESTATE_ELOOP)
		file_errors(filename);
	else if (errno == ESTATE_ENAMETOOLONG)
		file_errors(filename);
	else if (errno == ESTATE_ENOENT)
		file_errors(filename);
	else if (errno == ESTATE_ENOMEM)
		sys_errors();
	printf("filename: %s\n", filename);
	// else if (errno == ESTATE_ENOTDIR)
	// 	;//Подумать
	return (SUCCESSFUL_COMPLETION);
}

/*
	Возможные ошибки:
		1) Доступ запрещен
		2) каталога
		3) Это не каталог
*/
