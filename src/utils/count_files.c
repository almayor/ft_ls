/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 01:12:30 by unite             #+#    #+#             */
/*   Updated: 2020/06/24 01:12:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

ssize_t		count_files(const char *path)
{
	DIR		*dir;
	ssize_t	count;

	if (!(dir = opendir(path)))
		return (-1);
	count = 0;
	while (readdir(dir))
		count++;
	closedir(dir);
	return (count);
}
