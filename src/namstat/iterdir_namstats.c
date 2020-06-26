/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterdir_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 05:21:10 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 23:42:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	iterdir_namstats(t_namstat **nst)
{
	t_namstat	**dir_nst;
	int			first;
	int			multi;

	if (!nst)
		return ;
	first = 1;
	multi = nst[1] != NULL;
	while (*nst)
	{
		if (!first)
			ft_putstr("\n");
		if (!(dir_nst = getdir_namstats((*nst)->path)))
			ft_printf("ft_ls: %s: %s\n", (*nst)->path, strerror(errno));
		else
		{
			if (multi)
				ft_printf("%s:\n", (*nst)->path);
			process_namstats(dir_nst);
			free_namstats(dir_nst);
		}
		first = 0;
		nst++;
	}
}
