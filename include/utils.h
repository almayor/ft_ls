/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/06/28 09:04:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_tab(char **tab);
int		ft_atoi2(const char *str, int *resp);
char	*ft_ldtoa2(long double num, size_t precision, char *buf);
char	*ft_lltoa2(long long num, char *buf);
char	*ft_ulltoa2(unsigned long long num, char *buf);
char	*get_basename(char *buf, const char *path);
char	*join_path(char *buf, const char *path, const char *name);
size_t	len_tab(char **tab);
void	sort_tab(char **tab);

#endif
