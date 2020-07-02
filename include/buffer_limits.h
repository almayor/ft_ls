/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_limits.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 05:09:09 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 02:00:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_LIMITS_H
# define BUFFER_LIMITS_H

/*
** Idea borrowed from stackoverflow.com/questions/43787672/
** NOTE: not using functional macros as they are forbidden by the Norm
*/

# define UINTMAX_LENGTH	(241 * sizeof(uintmax_t) / 100 + 1)
# define INTMAX_LENGTH	(241 * sizeof(intmax_t) / 100 + 1)

#endif
