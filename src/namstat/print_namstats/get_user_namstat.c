/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_namstat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:08:20 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 09:29:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_user_namstat(t_namstat *nst)
{
	struct passwd	*passwd;
	static char		uid[UID_T_BOUND + 1];

	if (g_opt.n)
	{
		ft_memset(uid, 0, UID_T_BOUND + 1);
		return (ft_ulltoa2(nst->stat.st_uid, uid));
	}
	if (!(passwd = getpwuid(nst->stat.st_uid)))
		return (NULL);
	return (passwd->pw_name);
}
