/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_namstats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:33:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 21:17:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_namstats(t_namstat **nst)
{
	while (*nst)
	{
		ft_printf("%s%s%s%s\n",
			get_color_namstat(*nst),
			(*nst)->base,
			BG_DEF FG_DEF,
			get_suffix_namstat(*nst));
		nst++;
	}
}
