/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_blocksize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:28:02 by unite             #+#    #+#             */
/*   Updated: 2020/07/11 20:10:31 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_numeric_str(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

void		get_blocksize(void)
{
	char	*blk_s;

	if (g_opt.k)
		g_env.blksize = 1024;
	else if (!(blk_s = getenv("BLOCKSIZE")) ||
			ft_strlen(blk_s) == 0 ||
			!is_numeric_str(blk_s))
	{
		g_env.blksize = 512;
	}
	else if (ft_atoi2(blk_s, (int *)&(g_env.blksize)) ||
			g_env.blksize > 1000000000)
	{
		ft_dprintf(2, "ft_ls: maximum blocksize is 1G\n");
		g_env.blksize = 1000000000;
	}
	else if (g_env.blksize < 512)
	{
		ft_dprintf(2, "ft_ls: minimum blocksize is 512\n");
		g_env.blksize = 512;
	}
}
