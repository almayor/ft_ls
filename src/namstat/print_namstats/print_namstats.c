/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_namstats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:33:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 18:04:14 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	field_width(t_namstat **nst, char *(*fun)(t_namstat *))
{
	size_t		max;
	size_t		len;
	char		*str;

	max = 0;
	while (*nst)
	{
		if ((str = fun(*nst)) &&
			(len = ft_strlen(str)) > max)
			max = len;
		nst++;
	}
	return (max);
}

void			print_namstats(t_namstat **nst)
{
	t_namstat	**ptr;

	ptr = nst;
	while (*nst)
	{
		ft_printf("%s %*s  %-*s %-*s %*s %s %s %s\n",
			get_access_namstat(*nst),
			field_width(ptr, &get_nlink_namstat),
			get_nlink_namstat(*nst),
			field_width(ptr, &get_user_namstat),
			get_user_namstat(*nst),
			field_width(ptr, &get_group_namstat),
			get_group_namstat(*nst),
			field_width(ptr, &get_size_namstat),
			get_size_namstat(*nst),
			get_time_namstat(*nst),
			get_name_namstat(*nst),
			get_suffix_namstat(*nst));
		nst++;
	}
}
