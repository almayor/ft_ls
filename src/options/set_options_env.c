/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:59:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/29 09:41:43 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_options_env()
{
	if (ft_strequ(getenv("USER"), "root"))
		g_opt.A = 1;
	if (getenv("CLICOLOR"))
		g_opt.G = 1;
	if (!isatty(1) && !getenv("CLICOLOR_FORCE"))
		g_opt.G = 0;
	if (!isatty(1))
		g_opt._1 = 1;
}
