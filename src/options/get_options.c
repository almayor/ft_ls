/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 23:39:15 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 04:25:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	(*const g_dispatch_table[128])(void) = {
	['1'] = &set_option_1,
	['A'] = &set_option_A,
	['F'] = &set_option_F,
	['G'] = &set_option_G,
	['P'] = &set_option_P,
	['R'] = &set_option_R,
	['S'] = &set_option_S,
	['a'] = &set_option_a,
	['d'] = &set_option_d,
	['e'] = &set_option_e,
	['l'] = &set_option_l,
	['m'] = &set_option_m,
	['r'] = &set_option_r,
	['t'] = &set_option_t,
	['@'] = &set_option_at,
};

int			get_options(char ***argv)
{
	ft_memset(&g_opt, 0, sizeof(t_options));
	set_options_env();
	while (*(++(*argv)) && **argv[0] == '-' && ft_strlen(**argv) > 1)
	{
		while (*(++(**argv)))
		{
			if (g_dispatch_table[***argv])
				g_dispatch_table[***argv]();
			else
			{
				ft_printf("ft_ls: illegal option -- %c\n", ***argv);
				ft_printf("usage: ls [%s] [file ...]\n", OPTIONS);
				return (-1);
			}
		}
	}
	return (0);
}
