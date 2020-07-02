/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_simple_namstats.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 06:55:06 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 22:22:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_simple_namstats(t_namstat **nst)
{
	while (*nst)
	{
		ft_printf("%s%s%s%s\n",
			get_color_namstat(*nst),
			get_name_namstat(*nst),
			get_reset_color_namstat(*nst),
			get_suffix_namstat(*nst));
		nst++;
	}
}
