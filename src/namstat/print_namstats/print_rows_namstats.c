/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rows_namstats.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 06:38:10 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:44:01 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	get_colwidth(t_namstat **nst)
{
	size_t		max_len;
	size_t		name_len;

	max_len = 0;
	while (*nst)
	{
		name_len = (
			ft_strlen(get_name_namstat(*nst)) +
			ft_strlen(get_suffix_namstat(*nst)));
		if (name_len > max_len)
			max_len = name_len;
		nst++;
	}
	if (!g_opt.gg)
		max_len = max_len % 8 ? ceil_divide(max_len, 8) * 8 : max_len + 8;
	else
		max_len += 1;
	return (max_len);
}

static char		*get_fullname_namstat(t_namstat *nst)
{
	static char	fullname[NAME_MAX + 50];

	fullname[0] = '\0';
	ft_strcat(fullname, get_color_namstat(nst));
	ft_strcat(fullname, get_name_namstat(nst));
	ft_strcat(fullname, get_reset_color_namstat(nst));
	ft_strcat(fullname, get_suffix_namstat(nst));
	return (fullname);
}

static void		print_name_namstat(t_namstat *nst, size_t width, int isfinal)
{
	size_t	i;
	char	*fullname;
	size_t	escape_len;

	fullname = get_fullname_namstat(nst);
	escape_len = (
		ft_strlen(get_color_namstat(nst)) +
		ft_strlen(get_reset_color_namstat(nst)));
	if (isfinal)
		ft_printf("%-s\n", fullname);
	else if (g_opt.gg)
		ft_printf("%-*s", width + escape_len, fullname);
	else
	{
		ft_puts(fullname);
		i = 0;
		while (i++ < ceil_divide(width - ft_strlen(fullname), 8))
			ft_putchar('\t');
	}
}

static void		print_row_namstats(t_namstat **nst, size_t width,
									size_t ncols)
{
	size_t	j;

	j = 0;
	while (j < ncols)
	{
		print_name_namstat(*nst, width, j + 1 == ncols);
		nst += 1;
		j++;
	}
}

void			print_rows_namstats(t_namstat **nst)
{
	size_t	len;
	size_t	width;
	size_t	ncols;
	size_t	nrows;
	size_t	i;

	len = len_namstats(nst);
	width = get_colwidth(nst);
	ncols = g_env.cols < width ? 1 : g_env.cols / width;
	nrows = ceil_divide(len, g_env.cols < width ? 1 : g_env.cols / width);
	i = 0;
	while (i < nrows)
	{
		print_row_namstats(
			nst + i * ncols,
			width,
			i + 1 == nrows ? len % ncols : ncols);
		i++;
	}
}
