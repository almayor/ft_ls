/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_suffix_namstat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 05:08:07 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 22:05:08 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_suffix_namstat(t_namstat *nst)
{
	static char	suffix[2];

	ft_memset(suffix, 0, 2);
	if (g_opt.F && is_lnk_namstat(nst))
		suffix[0] = '@';
	if (g_opt.F && is_sock_namstat(nst))
		suffix[0] = '=';
	if (g_opt.F && is_wht_namstat(nst))
		suffix[0] = '%';
	if (g_opt.F && is_fifo_namstat(nst))
		suffix[0] = '|';
	if ((g_opt.p || g_opt.F) && is_dir_namstat(nst))
		suffix[0] = '/';
	if (g_opt.F && is_exe_namstat(nst))
		suffix[0] = '*';
	return (suffix);
}
