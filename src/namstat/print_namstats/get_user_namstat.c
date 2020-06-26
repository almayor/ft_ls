/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_namstat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:08:20 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 23:45:18 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_user_namstat(t_namstat *nst)
{
	struct passwd	*passwd;
	static char		uid[11];

	if (g_opt.n)
	{
		ft_memset(uid, 0, 11);
		return (ft_uint32_itoa2(uid, nst->stat.st_uid));
	}
	if (!(passwd = getpwuid(nst->stat.st_uid)))
		return (NULL);
	return (passwd->pw_name);
}
