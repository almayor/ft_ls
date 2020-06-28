/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_access_namstat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:16:50 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 09:12:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	get_type_namstat(t_namstat *nst)
{
	if (is_blk_namstat(nst))
		return ('b');
	if (is_chr_namstat(nst))
		return ('c');
	if (is_dir_namstat(nst))
		return ('d');
	if (is_lnk_namstat(nst))
		return ('l');
	if (is_sock_namstat(nst))
		return ('s');
	if (is_fifo_namstat(nst))
		return ('p');
	return ('-');
}

char		*get_access_namstat(t_namstat *nst)
{
	const char 	bits[] = "rwxrwxrwx";
	static char	access[12];
	size_t		i;

	ft_memset(access, 0, 12);
	access[0] = get_type_namstat(nst);
	i = 0;
	while (i < 9)
	{
		access[i + 1] = (nst->stat.st_mode & (1 << (8 - i))) ? bits[i] : '-';
		i++;
	}
	if (get_xattr_namstat(nst))
		access[11] = '@';
	else if (get_acl_namstat(nst))
		access[11] = '+';
	return (access);
}
