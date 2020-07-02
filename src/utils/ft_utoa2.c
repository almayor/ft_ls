/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:44:40 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 00:46:59 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_utoa2(uintmax_t num, char *buf)
{
	uintmax_t	factor;
	char		*ptr;

	ptr = buf;
	factor = 1;
	while (num / factor >= 10)
		factor *= 10;
	while (factor >= 1)
	{
		*(buf++) = num / factor + '0';
		num %= factor;
		factor /= 10;
	}
	*(buf++) = 0;
	return (ptr);
}
