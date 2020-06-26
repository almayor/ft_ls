/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir_namstat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 23:05:48 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 05:57:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_dir_nwoth_namstat(t_namstat *nst)
{
	return (is_dir_namstat(nst) &&
			!(nst->stat.st_mode & S_IWOTH));
}

int	is_dir_woth_nsticky_namstat(t_namstat *nst)
{
	return (is_dir_namstat(nst) &&
			(nst->stat.st_mode & S_IWOTH) &&
			!(nst->stat.st_mode & S_ISVTX));
}

int	is_dir_woth_sticky_namstat(t_namstat *nst)
{
	return (is_dir_namstat(nst) &&
			(nst->stat.st_mode & S_IWOTH) &&
			(nst->stat.st_mode & S_ISVTX));
}

int	is_dir_namstat(t_namstat *nst)
{
	return ((nst->stat.st_mode & S_IFMT) == S_IFDIR);
}
