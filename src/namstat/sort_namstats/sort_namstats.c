/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_namstats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:34:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/27 04:54:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	cmp_namstats(t_namstat *n1, t_namstat *n2)
{
	int	res;

	if ((g_opt.t && (
			(g_opt.c && (res = -cmp_ctime_namstats(n1, n2))) ||
			(g_opt.u && (res = -cmp_atime_namstats(n1, n2))) ||
			(g_opt.U && (res = -cmp_birthtime_namstats(n1, n2))) ||
			(!g_opt.c && !g_opt.u && !g_opt.U &&
				(res = -cmp_mtime_namstats(n1, n2))))) ||
		(g_opt.S && (res = -cmp_size_namstats(n1, n2))) ||
		(res = cmp_alnum_namstats(n1, n2)))
		return (g_opt.r ? -res : res);
	return (0);
}

void		sort_namstats(t_namstat **nst)
{
	size_t		len;
	size_t		i;
	t_namstat	*tmp;

	len = 0;
	while (nst[len])
		len++;
	while (len > 1)
	{
		i = 0;
		while (i < len - 1)
		{
			if (cmp_namstats(nst[i], nst[i + 1]) > 0)
			{
				tmp = nst[i];
				nst[i] = nst[i + 1];
				nst[i + 1] = tmp;
			}
			i++;
		}
		len--;
	}
}
