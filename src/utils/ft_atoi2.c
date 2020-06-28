/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:56:29 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 09:30:53 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_atoi2(const char *str, int *resp)
{
	long long	res;
	int			negative;

	while (ft_isspace(*str))
		str++;
	negative = 0;
	if (*str == '-' || *str == '+')
	{
		negative = *str == '-' ? 1 : 0;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 - (*str - '0');
		str++;
		if (negative && res < INT_MIN)
			return (1);
		if (!negative && res < -INT_MAX)
			return (-1);
	}
	*resp = negative ? res : -res;
	return (0);
}
