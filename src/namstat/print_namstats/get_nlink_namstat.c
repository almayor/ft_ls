/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nlink_namstat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:21:53 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 23:54:47 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_nlink_namstat(t_namstat *nst)
{
	static char	nlink[11];

	ft_memset(nlink, 0, 11);
	return (ft_uint32_itoa(nst->stat.st_nlink, nlink));
}
