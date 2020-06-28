/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:44:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/27 19:25:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	get_len(unsigned long long num)
{
	size_t	i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

char			*ft_ulltoa2(unsigned long long num, char *buf)
{
	size_t	len;

	len = get_len(num);
	while (num)
	{
		buf[--len] = num % 10 + '0';
		num /= 10;
	}
	return (buf);
}
