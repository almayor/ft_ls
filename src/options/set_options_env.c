/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:59:33 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 04:18:48 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_options_env()
{
	if (getenv("CLICOLOR"))
		g_opt.G = 1;
	if (ft_strequ(getenv("USER"), "root"))
		g_opt.A = 1;
}