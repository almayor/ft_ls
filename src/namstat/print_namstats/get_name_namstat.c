/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_namstat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:06:50 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 21:51:29 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_name_namstat(t_namstat *nst)
{
	static char	name[NAME_MAX + 1];

	ft_strcpy(name, nst->base);
	if (g_opt.q)
		printable_path(name);
	return (name);
}
