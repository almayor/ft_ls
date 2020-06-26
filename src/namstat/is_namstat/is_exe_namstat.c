/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exe_namstat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:05:48 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 04:42:15 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_exe_nuid_gid_namstat(t_namstat *nst)
{
	return (is_exe_namstat(nst) &&
			!(nst->stat.st_mode & S_ISUID) &&
			(nst->stat.st_mode & S_ISGID));
}

int	is_exe_uid_namstat(t_namstat *nst)
{
	return (is_exe_namstat(nst) &&
			(nst->stat.st_mode & S_ISUID));
}

int	is_exe_nuid_ngid_namstat(t_namstat *nst)
{
	return (is_exe_namstat(nst) &&
			!(nst->stat.st_mode & S_ISUID) &&
			!(nst->stat.st_mode & S_ISGID));
}

int	is_exe_namstat(t_namstat *nst)
{
	return (is_reg_namstat(nst) &&
			(nst->stat.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)));
}
