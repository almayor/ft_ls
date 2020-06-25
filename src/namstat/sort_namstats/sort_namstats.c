/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_namstats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:34:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 03:29:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	cmp_namstats(t_namstat *n1, t_namstat *n2, const t_options *opt)
{
	int	res;

	if (opt->t && (res = cmp_mtime_namstats(n1, n2)))
		return (res);
	if ((res = cmp_alnum_namstats(n1, n2)))
		return (res);
	return (0);
}

void		sort_namstats(t_namstat **nst, const t_options *opt)
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
			if (cmp_namstats(nst[i], nst[i + 1], opt) > 0)
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
