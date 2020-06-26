/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_ctime_namstats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:39:47 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 18:57:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp_ctime_namstats(t_namstat *n1, t_namstat *n2)
{
	struct timespec	n1_mtime;
	struct timespec	n2_mtime;

	n1_mtime = n1->stat.st_ctimespec;
	n2_mtime = n2->stat.st_ctimespec;
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
