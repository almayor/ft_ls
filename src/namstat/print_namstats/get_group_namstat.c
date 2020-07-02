/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_group_namstat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:14:56 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 03:20:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_group_namstat(t_namstat *nst)
{
	struct group	*group;
	static char		gid[GID_T_BOUND + 1];

	if (g_opt.o)
		return ("");
	if (g_opt.n)
		return (ft_utoa2(nst->stat.st_gid, gid));
	if (!(group = getgrgid(nst->stat.st_gid)))
		return (NULL);
	return (group->gr_name);
}
