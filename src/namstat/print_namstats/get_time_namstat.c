/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_namstat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:08:20 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:46:43 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_time_namstat(t_namstat *nst)
{
	char	*time;
	time_t	tv_sec;

	if (g_opt.c)
		tv_sec = nst->stat.st_ctimespec.tv_sec;
	else if (g_opt.u)
		tv_sec = nst->stat.st_atimespec.tv_sec;
	else if (g_opt.uu)
		tv_sec = nst->stat.st_birthtimespec.tv_sec;
	else
		tv_sec = nst->stat.st_mtimespec.tv_sec;
	time = ctime(&tv_sec);
	if (!g_opt.tt)
		time[16] = '\0';
	else
		time[24] = '\0';
	time += 4;
	return (time);
}
