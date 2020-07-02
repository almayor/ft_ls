/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 19:33:50 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 00:46:39 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_ftoa2(long double num, size_t precision, char *buf)
{
	size_t	i;

	ft_itoa2(num, buf);
	i = ft_strlen(buf);
	if (precision)
	{
		buf[i++] = '.';
		while (precision--)
		{
			num = (num - (long long)num) * 10;
			if (num > 0)
				buf[i++] = precision == 1 ? num + '0' : (num + 0.5) + '0';
			else
				buf[i++] = precision == 1 ? -num + '0' : -(num - 0.5) + '0';
		}
	}
	buf[i++] = 0;
	return (buf);
}
