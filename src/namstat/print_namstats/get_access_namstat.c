/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_access_namstat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:16:50 by unite             #+#    #+#             */
/*   Updated: 2020/07/09 16:26:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	set_type_namstat(t_namstat *nst, char* access)
{
	if (is_blk_namstat(nst))
		access[0] = 'b';
	else if (is_chr_namstat(nst))
		access[0] = 'c';
	else if (is_dir_namstat(nst))
		access[0] = 'd';
	else if (is_lnk_namstat(nst))
		access[0] = 'l';
	else if (is_sock_namstat(nst))
		access[0] = 's';
	else if (is_fifo_namstat(nst))
		access[0] = 'p';
	else
		access[0] = '-';
}

static void	set_acl_namstat(t_namstat *nst, char* access)
{
	acl_t		acl;
	acl_entry_t	entry;

	if ((acl = acl_get_link_np(nst->path, ACL_TYPE_EXTENDED)) &&
		(acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) > 0))
		access[10] = '+';
	else
		access[10] = ' ';
}

static void	set_xattr_namstat(t_namstat *nst, char* access)
{
	if (listxattr(nst->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		access[10] = '@';
	else
		access[10] = ' ';
}

static void set_flags_namstat(t_namstat *nst, char* access)
{
	if (nst->stat.st_mode & S_ISUID)
		access[3] = access[3] == 'x' ? 's' : 'S';
	if (nst->stat.st_mode & S_ISGID)
		access[6] = access[6] == 'x' ? 's' : 'S';
	if (nst->stat.st_mode & S_ISVTX)
		access[9] = access[9] == 'x' ? 't' : 'T';
}

char		*get_access_namstat(t_namstat *nst)
{
	const char	bits[] = "rwxrwxrwx";
	static char	access[12];
	size_t		i;

	i = 0;
	while (i < 9)
	{
		access[i + 1] = (nst->stat.st_mode & (1 << (8 - i))) ? bits[i] : '-';
		i++;
	}
	set_type_namstat(nst, access);
	set_acl_namstat(nst, access);
	set_xattr_namstat(nst, access);
	set_flags_namstat(nst, access);
	return (access);
}
