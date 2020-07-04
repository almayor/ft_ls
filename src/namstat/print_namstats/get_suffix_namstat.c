/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_suffix_namstat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 05:08:07 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:43:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_suffix_namstat(t_namstat *nst)
{
	static char	suffix[2];

	ft_memset(suffix, 0, 2);
	if (g_opt.ff && is_lnk_namstat(nst))
		suffix[0] = '@';
	if (g_opt.ff && is_sock_namstat(nst))
		suffix[0] = '=';
	if (g_opt.ff && is_wht_namstat(nst))
		suffix[0] = '%';
	if (g_opt.ff && is_fifo_namstat(nst))
		suffix[0] = '|';
	if ((g_opt.p || g_opt.ff) && is_dir_namstat(nst))
		suffix[0] = '/';
	if (g_opt.ff && is_exe_namstat(nst))
		suffix[0] = '*';
	return (suffix);
}
