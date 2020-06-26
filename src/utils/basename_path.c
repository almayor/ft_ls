/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_basename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:36:54 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 08:58:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_basename(char *buf, const char *path)
{
	const char	*last_slash;

	if ((last_slash = ft_strrchr(path, '/')))
		return (ft_strcpy(buf, last_slash + 1));
	else
		return (ft_strcpy(buf, path));
}
