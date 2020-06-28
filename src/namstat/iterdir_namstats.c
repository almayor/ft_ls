/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterdir_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 05:21:10 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 11:16:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	iterdir_namstats(t_namstat **nst)
{
	t_namstat	**dir_nst;
	int			multi;

	if (!nst)
		return ;
	multi = nst[1] != NULL;
	while (*nst)
	{
		if (!(dir_nst = getdir_namstats((*nst)->path)))
			ft_dprintf(2, "ft_ls: %s: %s\n", (*nst)->path, strerror(errno));
		else
		{
			if (multi)
				ft_printf("%s:\n", (*nst)->path);
			if (g_opt.l)
				ft_printf("total %lld\n", nblocks_namstats(dir_nst));
			process_namstats(dir_nst);
			free_namstats(dir_nst);
		}
		if (*(nst + 1))
			ft_puts("\n");
		nst++;
	}
}
