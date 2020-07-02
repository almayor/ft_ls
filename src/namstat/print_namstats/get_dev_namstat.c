/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dev_namstat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 05:13:15 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 04:36:12 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_dev_namstat(t_namstat *nst)
{
	static char	dev[7];

	ft_sprintf(dev, "%ju, %3ju",
		(uintmax_t)major(nst->stat.st_rdev),
		(uintmax_t)minor(nst->stat.st_rdev));
	return (dev);
}
