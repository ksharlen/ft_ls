/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:48:19 by ksharlen          #+#    #+#             */
/*   Updated: 2019/09/05 10:03:37 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR		*valid_opendir(const char *filename)
{
	DIR	*dir;

	errno = 0;
	dir = opendir(filename);
	if (errno == EOPENDIR_EACCES)
		file_errors(filename);
	else if (errno == EOPENDIR_ENOENT)
		file_errors(filename);
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

int		valid_stat(const char *filename, struct stat *buf, uint8_t f_type)
{
	errno = 0;
	if (f_type == L_TYPE)
		lstat(filename, buf);
	else
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
	// else if (errno == ESTATE_ENOTDIR)
	// 	;//Подумать
	return (SUCCESSFUL_COMPLETION);
}

char		*valid_readlink(const char *path_link)
{
	//!	Не проходит по норме
	int ret_rdl;
	char pull_val_link[MAX_LEN_FILENAME];

	ret_rdl = readlink(path_link, pull_val_link, MAX_LEN_FILENAME);
	errno = 0;
	if (errno == ENOTDIR || errno == EINVAL)
		;//?Тут подумать
	else if (errno == EINVAL)
		sys_errors();
	else if (errno == ENAMETOOLONG)
		sys_errors();
	else if (errno == ENOENT)
		file_errors(path_link);
	else if (errno == EACCES)
		file_errors(path_link);
	else if (errno == ELOOP)
		sys_errors();
	else if (errno == EIO)
		sys_errors();
	else if (errno == EFAULT)
		sys_errors();
	else if (errno == ENOMEM)
		sys_errors();
	pull_val_link[ret_rdl] = '\0';
	return (ft_strdup(pull_val_link));
}

/*
	Возможные ошибки:
		1) Доступ запрещен
		2) каталога
		3) Это не каталог
*/
