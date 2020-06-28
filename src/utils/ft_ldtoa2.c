/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 19:33:50 by unite             #+#    #+#             */
/*   Updated: 2020/06/27 19:47:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_ldtoa2(long double num, size_t precision, char *buf)
{
	size_t	i;

	ft_lltoa2(num, buf);
	if (precision)
	{
		ft_strcat(buf, ".");
		i = ft_strlen(buf);
		while (precision--)
		{
			num = (num - (long long)num) * 10;
			buf[i] = num + '0';
		}
	}
	return (buf);
}
