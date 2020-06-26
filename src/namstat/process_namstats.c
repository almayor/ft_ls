/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:32:05 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 21:26:12 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_namstats(t_namstat **nst)
{
	if (nst)
	{
		if (!g_opt.f)
			sort_namstats(nst);
		print_namstats(nst);
		if (g_opt.R)
			recurse_namstats(nst);
	}
}
