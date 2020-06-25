/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:34:53 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 08:53:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recurse_namstats(t_namstat **nst, const t_options *opt)
{
	int			first;
	t_namstat	**dir_nst;

	first = 1;
	while (*nst)
	{
		if (S_ISDIR((*nst)->stat.st_mode) &&
			!ft_strequ((*nst)->base, ".") &&
			!ft_strequ((*nst)->base, ".."))
		{
			if (!first)
				ft_putstr("\n");
			if (!(dir_nst = getdir_namstats((*nst)->path)))
				ft_printf("ft_ls: %s: %s\n", (*nst)->path, strerror(errno));
			else
			{
				ft_printf("%s:\n", (*nst)->path);
				process_namstats(dir_nst, opt);
				free_namstats(dir_nst);
			}
		}
		first = 0;
		nst++;
	}
}
