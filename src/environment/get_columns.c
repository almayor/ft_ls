/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_columns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:28:02 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 21:02:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_columns(void)
{
	struct winsize	win;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    g_env.cols = win.ws_col;
    if (!g_env.cols)
    	g_env.cols = 80;
}
