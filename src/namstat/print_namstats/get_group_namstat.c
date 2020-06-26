/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_group_namstat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:14:56 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 23:45:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_group_namstat(t_namstat *nst)
{
	struct group	*group;
	static char		gid[11];

	if (g_opt.n)
	{
		ft_memset(gid, 0, 11);
		return (ft_uint32_itoa2(gid, nst->stat.st_gid));
	}
	if (!(group = getgrgid(nst->stat.st_gid)))
		return (NULL);
	return (group->gr_name);
}
