/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_size_namstats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 01:39:47 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 20:20:59 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	cmp_size_namstats(t_namstat *n1, t_namstat *n2)
{
	if (n1->stat.st_size < n2->stat.st_size)
		return (-1);
	if (n1->stat.st_size > n2->stat.st_size)
		return (1);
	return (0);
}
