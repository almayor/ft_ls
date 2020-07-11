/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterdir_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 05:21:10 by unite             #+#    #+#             */
/*   Updated: 2020/07/11 19:28:49 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	iterdir_namstats(t_namstat **nst, int multi)
{
	t_namstat	**dir_nst;
	int			first;

	if (!nst)
		return ;
	first = 1;
	while (*nst)
	{
		if (!(dir_nst = getdir_namstats((*nst)->path)))
			ft_dprintf(2, "ft_ls: %s: %s\n", (*nst)->base, strerror(errno));
		else
		{
			if (!first)
				ft_puts("\n");
			if (multi)
				ft_printf("%s:\n", (*nst)->path);
			if (g_opt.l)
				ft_printf("total %lld\n", nblocks_namstats(dir_nst));
			process_namstats(dir_nst);
			free_namstats(dir_nst);
		}
		first = 0;
		errno = 0;
		nst++;
	}
}
