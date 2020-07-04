/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_birthtime_namstats.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:39:47 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:23:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#ifdef _DARWIN_FEATURE_64_BIT_INODE

int	cmp_birthtime_namstats(t_namstat *n1, t_namstat *n2)
{
	struct timespec	n1_mtime;
	struct timespec	n2_mtime;

	n1_mtime = n1->stat.st_birthtimespec;
	n2_mtime = n2->stat.st_birthtimespec;
	if (n1_mtime.tv_sec < n2_mtime.tv_sec)
		return (-1);
	if (n1_mtime.tv_sec > n2_mtime.tv_sec)
		return (1);
	if (n1_mtime.tv_nsec < n2_mtime.tv_nsec)
		return (-1);
	if (n1_mtime.tv_nsec > n2_mtime.tv_nsec)
		return (1);
	return (0);
}

#else

int	cmp_birthtime_namstats(t_namstat *n1, t_namstat *n2)
{
	return (cmp_ctime_namstats(n1, n2));
}

#endif
