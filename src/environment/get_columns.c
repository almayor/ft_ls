/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_columns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:28:02 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 20:25:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_columns(void)
{
	struct winsize	win;

	if (!isatty(1))
		g_env.cols = 80;
	else
	{
		if (getenv("COLUMNS"))
			ft_atoi2(getenv("COLUMNS"), &(g_env.cols));
		else
		{
			ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
			g_env.cols = win.ws_col;
		}
		if (!g_env.cols)
			g_env.cols = 80;
	}
}
