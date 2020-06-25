/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_namstat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 01:15:55 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 08:54:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_namstat	*get_namstat(const char *path)
{
	t_namstat	*nst;

	if (!(nst = ft_calloc(sizeof(t_namstat), 1)))
		return (NULL);
	ft_strcpy(nst->path, path);
	get_basename(nst->base, path);
	if (stat(nst->path, &(nst->stat)))
	{
		free(nst);
		nst = NULL;
	}
	return (nst);
}
