/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:26:07 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 08:30:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*join_path(char *buf, const char *path, const char *name)
{
	size_t		pathlen;
	size_t		namelen;

	pathlen = ft_strlen(path);
	namelen = ft_strlen(name);
	ft_memset(buf, 0, pathlen + namelen + 2);
	ft_strcpy(buf, path);
	if (path[pathlen - 1] != '/')
		ft_strcat(buf, "/");
	ft_strcat(buf, name);
	return (buf);
}
