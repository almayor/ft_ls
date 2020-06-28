/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_blocksize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:28:02 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 09:02:57 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_numeric_str(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

void		get_blocksize(void)
{
	char	*blk_s;

	if (!(blk_s = getenv("BLOCKSIZE")) || ft_strlen(blk_s) == 0)
		g_env.blksize = 512;
	else if (!is_numeric_str(blk_s))
	{
		ft_dprintf(2, "ft_ls: %s: unknown blocksize\n", blk_s);
		g_env.blksize = 512;
	}
	else if (ft_atoi2(blk_s, &(g_env.blksize)) < 0)
	{
		ft_dprintf(2, "ft_ls: minimum blocksize is 512\n");
		g_env.blksize = 512;
	}
	else if (ft_atoi2(blk_s, &(g_env.blksize)) > 0)
	{
		ft_dprintf(2, "ft_ls: maximum blocksize is 1G\n");
		g_env.blksize = 1000000000;
	}	
}
