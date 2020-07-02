/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_dev_namstat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 01:57:03 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 01:20:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*get_dev_namstat(t_namstat *nst)
{
	static char	dev[7];

	ft_sprintf(dev, "%ju, %3ju",
		(uintmax_t)major(nst->stat.st_rdev),
		(uintmax_t)minor(nst->stat.st_rdev));
	return (dev);
}

static char	*get_size_namstat(t_namstat *nst)
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

char		*get_size_dev_namstat(t_namstat *nst)
{
	if (is_blk_namstat(nst) || is_chr_namstat(nst))
		return (get_dev_namstat(nst));
	else
		return (get_size_namstat(nst));
}
