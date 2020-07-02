/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 23:39:15 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 23:31:43 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	(*const g_dispatch_table[128])(void) = {
	['1'] = &set_option_1,
	['A'] = &set_option_A,
	['C'] = &set_option_C,
	['F'] = &set_option_F,
	['G'] = &set_option_G,
	['L'] = &set_option_L,
	['R'] = &set_option_R,
	['S'] = &set_option_S,
	['T'] = &set_option_T,
	['U'] = &set_option_U,
	['a'] = &set_option_a,
	['c'] = &set_option_c,
	['d'] = &set_option_d,
	['e'] = &set_option_e,
	['f'] = &set_option_f,
	['h'] = &set_option_h,
	['i'] = &set_option_i,
	['k'] = &set_option_k,
	['l'] = &set_option_l,
	['m'] = &set_option_m,
	['n'] = &set_option_n,
	['o'] = &set_option_o,
	['p'] = &set_option_p,
	['q'] = &set_option_q,
	['r'] = &set_option_r,
	['s'] = &set_option_s,
	['t'] = &set_option_t,
	['u'] = &set_option_u,
	['v'] = &set_option_v,
	['x'] = &set_option_x,
	['@'] = &set_option_at,
};

int			get_options(char ***argv)
{
	set_options_env();
	while (*(++(*argv)) && **argv[0] == '-' && ft_strlen(**argv) > 1)
	{
		while (*(++(**argv)))
		{
			if (g_dispatch_table[***argv])
				g_dispatch_table[***argv]();
			else
			{
				ft_dprintf(2, "ft_ls: illegal option -- %c\n", ***argv);
				ft_dprintf(2, "usage: ls [%s] [file ...]\n", OPTIONS);
				return (-1);
			}
		}
	}
	return (0);
}
