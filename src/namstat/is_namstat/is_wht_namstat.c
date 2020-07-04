/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wht_namstat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:05:48 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:05:18 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#ifdef S_IFWHT

int	is_wht_namstat(t_namstat *nst)
{
	return ((nst->stat.st_mode & S_IFMT) == S_IFWHT);
}

#else

int	is_wht_namstat(t_namstat *nst)
{
	return (0);
}

#endif
