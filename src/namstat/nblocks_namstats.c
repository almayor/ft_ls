/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nblocks_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 06:44:11 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 23:52:29 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


blkcnt_t	nblocks_namstats(t_namstat	**nst)
{
	blkcnt_t	nblocks;

	nblocks = 0;
	while (*nst)
	{
		if (!is_blk_namstat(*nst) && !is_chr_namstat(*nst))
			nblocks += (*nst)->stat.st_blocks / (g_env.blksize / 512);
		nst++;
	}
	return (nblocks);
}
