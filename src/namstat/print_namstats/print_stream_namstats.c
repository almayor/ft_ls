/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stream_namstats.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 06:55:06 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 22:57:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_stream_namstats(t_namstat **nst)
{
	char		*name_len;
	size_t		col_remain;
	size_t		len_print_name;

	col_remain = g_env.cols;
	while (*nst)
	{
		len_print_name = (
			ft_strlen(get_name_namstat(*nst)) +
			ft_strlen(get_suffix_namstat(*nst)));
		len_print_name += nst[1] ? 2 : 1;
		if (len_print_name > col_remain)
		{
			ft_putchar('\n');
			col_remain = g_env.cols;
		}
		ft_printf("%s%s%s%s%s",
			get_color_namstat(*nst),
			get_name_namstat(*nst),
			get_reset_color_namstat(*nst),
			get_suffix_namstat(*nst),
			nst[1] ? ", " : "\n");
		col_remain -= len_print_name;
		nst++;
	}
}
