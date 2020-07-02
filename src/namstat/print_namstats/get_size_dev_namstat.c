/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_dev_namstat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 01:57:03 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 01:59:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_size_dev_namstat(t_namstat *nst)
{
	if (is_blk_namstat(nst) || is_chr_namstat(nst))
		return (get_dev_namstat(nst));
	else
		return (get_size_namstat(nst));
}
