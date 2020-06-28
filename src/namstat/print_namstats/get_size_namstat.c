/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_namstat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 05:13:15 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 11:03:02 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_size_namstat(t_namstat *nst)
{
	static char	size[OFF_T_BOUND + 1];
	const char	*units[] = {"B", "K", "M", "G", "T", "P"};
	long double	frac;
	size_t		i;

	ft_memset(size, 0, OFF_T_BOUND + 1);
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
			ft_ldtoa2(frac, 1, size);
		else
			ft_ulltoa2(frac, size);
		return (ft_strcat(size, units[i]));
	}
	else
		return (ft_lltoa2(nst->stat.st_size, size));
}
