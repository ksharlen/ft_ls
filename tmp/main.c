/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:13:26 by ksharlen          #+#    #+#             */
/*   Updated: 2019/08/29 09:56:17 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/xattr.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/acl.h>
#include <sys/stat.h>
#include <pwd.h>


#define P_UNUSED(x) (void)(x)

// int main (int argc, char **argv)
// {
//     acl_t acl = NULL;
//     acl_entry_t dummy;
//     ssize_t xattr = 0;
//     char chr;
// 	char *filename = argv[1];
//     //char * filename = "/Users/john/desktop/mutations.txt";

//     acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
// 	printf("acl: %zd\n", acl);
//     if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
//         acl_free(acl);
//         acl = NULL;
//     }
//     xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
//     if (xattr < 0)
//         xattr = 0;

//     if (xattr > 0)
//         chr = '@';
//     else if (acl != NULL)
//         chr = '+';
//     else
//         chr = ' ';

//     printf("%c\n", chr);
// }

// int		main(int argc, char **argv)
// {
// 	struct stat *buf;
// 	char *pw_name;

// 	printf("sizeof: %zd\n", sizeof(struct stat));
// 	buf = (struct stat *)malloc(sizeof(struct stat));
// 	stat(argv[1], buf);
// 	pw_name = getpwuid(buf->st_uid)->pw_name;
// 	printf("%s\n", pw_name);
// 	free(buf);
// 	// acl_type_t	type = ACL_TYPE_ACCESS;
// 	// acl_type_t  typeD = ACL_TYPE_DEFAULT;
// 	// acl_type_t	typeE = ACL_TYPE_EXTENDED;
// 	// acl_t		acl = NULL;
// 	// ssize_t		xattr = 0;

// 	// acl = acl_get_file(argv[1], typeE);
// 	// xattr = listxattr(argv[1], NULL, 0, XATTR_NOFOLLOW);
// 	// printf("xattr: %zd\n", xattr);
// 	// if (acl == NULL)
// 	// 	printf("NO\n");
// 	// else
// 	// 	printf("YES\n");
// 	//ft_printf("user  %s  %d", "", 84);
// 	return (0);
// }

int		main(void)
{
	//printf("\e[;37mhello world\n");
	printf("\e[32;41;1mhello world\n");
	return (0);
}