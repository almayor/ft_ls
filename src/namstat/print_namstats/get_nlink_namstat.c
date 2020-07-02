/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nlink_namstat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:21:53 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 00:47:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_nlink_namstat(t_namstat *nst)
{
	static char	nlink[NLINK_T_BOUND + 1];

	return (ft_utoa2(nst->stat.st_nlink, nlink));
}
