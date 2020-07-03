/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_simple_namstats.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 06:55:06 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 22:46:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char *(* const g_funs[])(t_namstat *) = {
	&get_nblocks_namstat,
	&get_color_namstat,
	&get_name_namstat,
	&get_reset_color_namstat,
	&get_suffix_namstat,
};

static const char *g_fmts[] = {
	"%*s ",
	"%.*s",
	"%-.*s",
	"%.*s",
	"%.*s",
};

static size_t	*get_field_widths(t_namstat **nst)
{
	static size_t	widths[5];
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	while (i < 5)
	{
		widths[i] = 0;
		j = 0;
		while (nst[j])
		{
			str = g_funs[i](nst[j]);
			if (ft_strlen(str) > widths[i])
				widths[i] = ft_strlen(str);
			j++;
		}
		i++;
	}
	return (widths);
}

void	print_simple_namstats(t_namstat **nst)
{
	size_t			*widths;
	size_t			i;

	widths = get_field_widths(nst);
	while (*nst)
	{
		i = 0;
		while (i < 5)
		{ 
			if (widths[i])
				ft_printf(g_fmts[i], widths[i], g_funs[i](*nst));
			i++;
		}
		ft_puts("\n");
		nst++;
	}
}
