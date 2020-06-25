/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_namstats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:32:05 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 05:19:59 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_namstats(t_namstat **nst, const t_options *opt)
{
	if (nst)
	{
		sort_namstats(nst, opt);
		print_namstats(nst, opt);
		if (opt->R)
			recurse_namstats(nst, opt);
	}
}
