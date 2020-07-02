/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_namstat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:06:50 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 04:42:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_name_namstat(t_namstat *nst)
{
	static char	name[20 + NAME_MAX + 20 + 4 + PATH_MAX + 1];
	char		link[PATH_MAX + 1];

	name[0] = '\0';
	if (g_opt.G)
	{
		ft_strcat(name, get_color_namstat(nst));
		ft_strcat(name, nst->base);
		ft_strcat(name, BG_DEF FG_DEF);
	}
	else
		ft_strcat(name, nst->base);
	ft_strcat(name, get_suffix_namstat(nst));
	if (is_lnk_namstat(nst))
	{
		ft_memset(link, 0, PATH_MAX + 1);
		ft_strcat(name, " -> ");
		if (readlink(nst->path, link, PATH_MAX + 1) < 0)
			perror("ft_ls");
		ft_strcat(name, link);
	}
	return (name);
}
