/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_namstats.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:33:33 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 01:56:51 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char *(* const g_funs[])(t_namstat *) = {
	&get_ino_namstat,
	&get_nblocks_namstat,
	&get_access_namstat,
	&get_nlink_namstat,
	&get_user_namstat,
	&get_group_namstat,
	&get_size_dev_namstat,
	&get_time_namstat,
	&get_color_namstat,
	&get_name_namstat,
	&get_reset_color_namstat,
	&get_suffix_namstat,
	&get_lpath_namstat
};

static const char *g_fmts[] = {
	"%*s ",
	"%*s ",
	"%*s",
	" %*s",
	" %-*s ",
	" %-*s ",
	" %*s",
	" %*s",
	" %.*s",
	"%-.*s",
	"%.*s",
	"%.*s",
	"%.*s",
};

static size_t	*get_field_widths(t_namstat **nst)
{
	static size_t	widths[13];
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	while (i < 13)
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

static void		set_local_options(t_namstat **nst)
{
	while (*nst)
	{
		if (is_blk_namstat(*nst) || is_chr_namstat(*nst))
			g_opt.h = 0;
		nst++;
	}
}

void			print_long_namstats(t_namstat **nst)
{
	size_t			*widths;
	t_options		opt_bk;
	size_t			i;

	opt_bk = g_opt;
	set_local_options(nst);
	widths = get_field_widths(nst);
	while (*nst)
	{
		i = 0;
		while (i < 13)
		{ 
			if (widths[i])
				ft_printf(g_fmts[i], widths[i], g_funs[i](*nst));
			i++;
		}
		ft_puts("\n");
		nst++;
	}
	g_opt = opt_bk;
}
