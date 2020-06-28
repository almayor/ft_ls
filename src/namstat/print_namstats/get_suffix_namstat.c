/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_suffix_namstat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 05:08:07 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 11:30:49 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_suffix_namstat(t_namstat *nst)
{
	if (g_opt.F && is_lnk_namstat(nst))
		return ("@");
	if (g_opt.F && is_sock_namstat(nst))
		return ("=");
	if (g_opt.F && is_wht_namstat(nst))
		return ("%");
	if (g_opt.F && is_fifo_namstat(nst))
		return ("|");
	if ((g_opt.p || g_opt.F) && is_dir_namstat(nst))
		return ("/");
	if (g_opt.F && is_exe_namstat(nst))
		return ("*");
	return ("");
}
