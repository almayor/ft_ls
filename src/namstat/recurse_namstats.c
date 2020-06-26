/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:34:53 by unite             #+#    #+#             */
/*   Updated: 2020/06/27 01:33:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recurse_namstats(t_namstat **nst)
{
	int			first;
	t_namstat	**dir_nst;

	first = 1;
	while (*nst)
	{
		if (!ft_strequ((*nst)->base, ".") && !ft_strequ((*nst)->base, "..") &&
			is_dir_namstat(*nst))
		{
			if (!first)
				ft_putstr("\n");
			if (!(dir_nst = getdir_namstats((*nst)->path)))
				ft_dprintf(2, "ft_ls: %s: %s\n", (*nst)->path, strerror(errno));
			else
			{
				ft_printf("%s:\n", (*nst)->path);
				// if (g_opt.l)
					ft_printf("total %lld", nblocks_namstats(dir_nst));
				process_namstats(dir_nst);
				free_namstats(dir_nst);
			}
		}
		first = 0;
		nst++;
	}
}
