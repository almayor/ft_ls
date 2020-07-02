/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdir_namstats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:39:03 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 01:38:20 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			is_printed(const char *name)
{
	return (name[0] != '.' ||
			(g_opt.a) ||
			(g_opt.A &&
				!ft_strequ(name, ".") &&
				!ft_strequ(name, "..")));
}

static ssize_t		count_files(const char *path)
{
	struct dirent	*dirent;
	DIR		*dir;
	ssize_t	count;

	if (!(dir = opendir(path)))
		return (-1);
	count = 0;
	while ((dirent = readdir(dir)))
	{
		if (is_printed(dirent->d_name))
			count++;
	}
	closedir(dir);
	return (count);
}

static t_namstat	*next_namstat(DIR *dir, const char *path)
{
	struct dirent	*dirent;
	char			pathname[PATH_MAX];
	t_namstat		*nst;

	while ((dirent = readdir(dir)))
	{
		if (is_printed(dirent->d_name))
		{
			join_path(pathname, path, dirent->d_name);
			return (get_namstat(pathname));
		}
	}
	return (NULL);
}

t_namstat	**getdir_namstats(const char *path)
{
	DIR				*dir;
	t_namstat		**nst;
	ssize_t			count;
	size_t			i;

	if ((count = count_files(path)) >= 0 &&
		(nst = ft_calloc(sizeof(t_namstat *), count + 1)) &&
		(dir = opendir(path)))
	{
		i = 0;
		while (i < count)
		{
			if (!(nst[i++] = next_namstat(dir, path)))
			{
				free_namstats(nst);
				nst = NULL;
				break ;
			}
		}
		closedir(dir);
	}
	return (nst);
}
