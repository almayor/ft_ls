/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nblocks_namstat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 05:13:15 by unite             #+#    #+#             */
/*   Updated: 2020/07/11 20:05:31 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_nblocks_namstat(t_namstat *nst)
{
	static char	nblocks_s[UINTMAX_LENGTH + 1];
	blkcnt_t	nblocks;

	if (g_opt.s)
	{
		if (g_opt.k)
			nblocks = ceil_divide(nst->stat.st_blocks, 2);
		else
			nblocks = ceil_divide(nst->stat.st_blocks, g_env.blksize / 512);
		ft_sprintf(nblocks_s, "%ju", nblocks);
	}
	else
		nblocks_s[0] = '\0';
	return (nblocks_s);
}
