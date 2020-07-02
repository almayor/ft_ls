/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 21:06:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

uintmax_t	ceil_divide(uintmax_t a, uintmax_t b);

int			ft_atoi2(const char *str, int *resp);
char		*ft_ftoa2(long double num, size_t precision, char *buf);
char		*ft_itoa2(intmax_t num, char *buf);
char		*ft_utoa2(uintmax_t num, char *buf);

void		free_tab(char **tab);
void		sort_tab(char **tab);
size_t		len_tab(char **tab);

char		*basename_path(char *buf, const char *path);
char		*join_path(char *buf, const char *path, const char *name);
char		*printable_path(char *path);

#endif
