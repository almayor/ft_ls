/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nblocks_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 06:44:11 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 22:17:10 by unite            ###   ########.fr       */
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
			nblocks += (*nst)->stat.st_blocks;
		nst++;
	}
	return (nblocks);
}
