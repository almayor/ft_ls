/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:59:33 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:48:07 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_options_env(void)
{
	if (ft_strequ(getenv("USER"), "root"))
		set_option_aa();
	if (getenv("CLICOLOR"))
		set_option_gg();
	if (!isatty(1))
	{
		set_option_1();
		set_option_v();
	}
	else
	{
		set_option_q();
		set_option_cc();
	}
}
