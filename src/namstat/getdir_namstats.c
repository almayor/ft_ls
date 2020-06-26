/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdir_namstats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:39:03 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 23:41:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_namstat	**getdir_namstats(const char *path)
{
	DIR				*dir;
	struct dirent	*direntp;
	t_namstat		**nst;
	ssize_t			count;
	char			pathname[PATH_MAX];

	if ((count = count_files(path)) < 0 ||
		!(nst = ft_calloc(sizeof(t_namstat *), count + 1)))
		return (NULL);
	if ((dir = opendir(path)))
	{
		while (count)
			if (!(direntp = readdir(dir)) ||
				!join_path(pathname, path, direntp->d_name) ||
				!(nst[--count] = get_namstat(pathname)))
			{
				free_namstats(nst);
				return (NULL);
			}
		closedir(dir);
	}
	return (nst);
}
