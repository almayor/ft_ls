/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 23:39:15 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 04:47:16 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_options_single(const char *arg, t_options *opt)
{
	while (*(++arg))
	{
		if (*arg == 't')
			opt->t = 1;
		else if (*arg == 'a')
			opt->a = 1;
		else if (*arg == 'R')
			opt->R = 1;
		else if (*arg == 'd')
			opt->d = 1;
		else if (*arg == 'l')
			opt->l = 1;
		else if (*arg == 'G')
			opt->G = 1;
		else if (*arg == 'r')
			opt->r = 1;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", *arg);
			ft_printf("usage: ls [%s] [file ...]\n", OPTIONS);
			return (-1);
		}
	}
	return (0);
}

int			get_options(char ***argv, t_options *opt)
{
	(*argv)++;
	ft_memset(opt, 0, sizeof(t_options));
	while (**argv && **argv[0] == '-' && ft_strlen(**argv) > 1)
	{
		if (get_options_single(**argv, opt))
			return (-1);
		(*argv)++;
	}
	return (0);
}
