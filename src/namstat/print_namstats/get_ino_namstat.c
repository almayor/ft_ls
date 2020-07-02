/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ino_namstat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 04:33:06 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 00:49:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_ino_namstat(t_namstat *nst)
{
	static char	ino[INO_T_BOUND + 1];

	if (g_opt.i)
		return (ft_utoa2(nst->stat.st_ino, ino));
	else
		return ("");
}
