/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:34:53 by unite             #+#    #+#             */
/*   Updated: 2020/07/11 19:28:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_special_name(char *name)
{
	return (ft_strequ(name, ".") || ft_strequ(name, ".."));
}

void		recurse_namstats(t_namstat **nst)
{
	t_namstat	**dir_nst;

	while (*nst)
	{
		if (!is_special_name((*nst)->base) && is_dir_namstat(*nst))
		{
			ft_printf("\n%s:\n", (*nst)->path);
			if (!(dir_nst = getdir_namstats((*nst)->path)))
				ft_dprintf(2, "ft_ls: %s: %s\n", (*nst)->base, strerror(errno));
			else
			{
				if (g_opt.l)
					ft_printf("total %lld\n", nblocks_namstats(dir_nst));
				process_namstats(dir_nst);
				free_namstats(dir_nst);
			}
		}
		errno = 0;
		nst++;
	}
}
