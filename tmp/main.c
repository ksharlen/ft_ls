/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:00:57 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/13 07:35:38 by ksharlen         ###   ########.fr       */
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



int		main(int argc, char **argv)
{
	DIR	*dir;
	struct dirent *dent;

	req_rdallfiles(argv[1], 1);
	return (0);
}
