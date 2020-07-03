/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_namstat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:08:20 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 23:28:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_user_namstat(t_namstat *nst)
{
	struct passwd	*passwd;
	static char		uid[UINTMAX_LENGTH + 1];

	if (g_opt.n)
		return (ft_utoa2(nst->stat.st_uid, uid));
	if (!(passwd = getpwuid(nst->stat.st_uid)))
		return (NULL);
	return (passwd->pw_name);
}
