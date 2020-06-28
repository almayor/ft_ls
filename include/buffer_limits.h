/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_limits.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 05:09:09 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 04:31:46 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_LIMITS_H
# define BUFFER_LIMITS_H

/*
** Idea borrowed from stackoverflow.com/questions/43787672/
** NOTE: not using functional macros as they are forbidden by the Norm
*/

# define OFF_T_BOUND	(241 * sizeof(off_t) / 100 + 1)
# define UID_T_BOUND	(241 * sizeof(uid_t) / 100 + 1)
# define GID_T_BOUND	(241 * sizeof(gid_t) / 100 + 1)
# define NLINK_T_BOUND	(241 * sizeof(nlink_t) / 100 + 1)
# define INO_T_BOUND	(241 * sizeof(ino_t) / 100 + 1)

#endif
