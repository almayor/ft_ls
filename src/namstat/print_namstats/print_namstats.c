/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_namstats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 06:53:18 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 21:30:18 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_namstats(t_namstat **nst)
{
	if (g_opt.l)
		print_long_namstats(nst);
	else if (g_opt.m)
		print_stream_namstats(nst);
	else if (g_opt.x)
		print_rows_namstats(nst);
	else if (g_opt._1)
		print_simple_namstats(nst);
	else
		print_cols_namstats(nst);
}
