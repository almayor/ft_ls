/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 03:29:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

typedef struct	s_environment
{
	blksize_t	blksize;
	char		lscolors[23];
	int			cols;
}				t_environment;

extern t_environment	g_env;

void			get_blocksize(void);
void			get_columns(void);
int				get_environment(void);
void			get_lscolors(void);

#endif
