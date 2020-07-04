/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_namstat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 01:15:55 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:44:33 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_namstat	*get_namstat(const char *path)
{
	t_namstat	*nst;

	if (!(nst = ft_calloc(sizeof(t_namstat), 1)))
		return (NULL);
	ft_strcpy(nst->path, path);
	basename_path(nst->base, nst->path);
	if ((!g_opt.ll && lstat(nst->path, &(nst->stat))) ||
		(g_opt.ll && stat(nst->path, &(nst->stat))))
	{
		free(nst);
		nst = NULL;
	}
	return (nst);
}
