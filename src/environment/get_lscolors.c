/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lscolors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:58:59 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 09:05:45 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_lscolors(void)
{
	char		*lsc;
	size_t		i;

	ft_memset(g_env.lscolors, 'x', 22);
	if (!(lsc = getenv("LSCOLORS")))
	{
		ft_strcpy(g_env.lscolors, "exfxcxdxbxegedabagacad");
		return ;
	}
	i = 0;
	while (i < 22)
	{
		if (!ft_strchr("abcdefghABCDEFGHx", lsc[i]))
			ft_dprintf(2, "invalid character '%c' in LSCOLORS env var", lsc[i]);
		else
			g_env.lscolors[i] = lsc[i];
		i++;
	}
}
