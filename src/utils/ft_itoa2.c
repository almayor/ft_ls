/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:44:40 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 00:47:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_itoa2(intmax_t num, char *buf)
{
	intmax_t	factor;
	char		*ptr;

	ptr = buf;
	factor = num < 0 ? -1 : 1;
	while (num / factor >= 10)
		factor *= 10;
	if (num < 0)
		*(buf++) = '-';
	while (factor >= 1 || factor <= -1)
	{
		*(buf++) = num / factor + '0';
		num %= factor;
		factor /= 10;
	}
	*(buf++) = 0;
	return (ptr);
}
