/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_namstats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:33:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 05:59:47 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_namstats(t_namstat **nst)
{
	static char	*def_escape = BG_DEF""FG_DEF;

	while (*nst)
	{
		if ((*nst)->base[0] != '.' ||
			(g_opt.a) ||
			(g_opt.A &&
				!ft_strequ((*nst)->base, ".") &&
				!ft_strequ((*nst)->base, "..")))
			ft_printf("%s%s%s%s%s",
				get_color_namstat(*nst),
				(*nst)->base,
				BG_DEF FG_DEF,
				get_suffix_namstat(*nst),
				g_opt.m ? ", " : "\n");
		nst++;
	}
}
