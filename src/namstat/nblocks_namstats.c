/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nblocks_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 06:44:11 by unite             #+#    #+#             */
/*   Updated: 2020/07/11 20:15:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

blkcnt_t	nblocks_namstats(t_namstat **nst)
{
	uintmax_t	tot_512blk;

	tot_512blk = 0;
	while (*nst)
	{
		tot_512blk += (*nst)->stat.st_blocks;
		nst++;
	}
	return (ceil_divide(tot_512blk, g_env.blksize / 512));
}
