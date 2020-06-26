/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint32_itoa2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:44:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 23:51:10 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	ft_uint32_len(unsigned long n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_uint32_itoa2(unsigned long num, char *buf)
{
	size_t			len;
	unsigned long	tmp;

	len = ft_uint32_len(n);
	tmp = n;
	buf[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		buf[--len] = tmp % 10 + '0';
	return (buf);
}
