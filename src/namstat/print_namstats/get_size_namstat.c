/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_namstat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 05:13:15 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 04:29:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_size_namstat(t_namstat *nst)
{
	static char	size[OFF_T_BOUND + 1];
	const char	*units[] = {"B", "K", "M", "G", "T", "P"};
	long double	frac;
	size_t		i;

	if (g_opt.h)
	{
		frac = nst->stat.st_size;
		i = 0;
		while (frac >= 1024)
		{
			frac /= 1024;
			i++;
		}
		if (frac < 10)
			ft_sprintf(size, " %.1f%s", frac, units[i]);
		else
			ft_sprintf(size, " %ju%s", (uintmax_t)frac, units[i]);
	}
	else
		ft_sprintf(size, " %ju", (uintmax_t)nst->stat.st_size);
	return (size);
}
