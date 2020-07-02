/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lpath_namstat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:38:12 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 01:21:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_lpath_namstat(t_namstat *nst)
{
	static char	link[PATH_MAX + 1 + 4];

	ft_memset(link, 0, PATH_MAX + 1);
	if (is_lnk_namstat(nst) && g_opt.l)
	{
		ft_strcat(link, " -> ");
		if (readlink(nst->path, link + 4, PATH_MAX + 1) < 0)
			perror("ft_ls");
		if (g_opt.q)
			printable_path(link);
	}
	return (link);
}
