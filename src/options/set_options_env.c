/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:59:33 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 21:46:52 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_options_env()
{
	if (ft_strequ(getenv("USER"), "root"))
		set_option_A();
	if (getenv("CLICOLOR"))
		set_option_G();
	if (!isatty(1))
	{
		set_option_1();
		set_option_v();
	}
	else
	{
		set_option_q();
		set_option_C();
	}
}
