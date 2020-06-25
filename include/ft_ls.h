/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:24:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 08:58:19 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

#include <limits.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include "libftprintfgnl.h"

typedef struct	s_namstat
{
	char		path[PATH_MAX + 1];
	char		base[NAME_MAX + 1];
	struct stat	stat;
}				t_namstat;

# define OPTIONS	"adlrtGR"

typedef struct	s_options
{
	int			a;
	int			d;
	int			l;
	int			r;
	int			t;
	int			G;
	int			R;
}				t_options;

int			cmp_alnum_namstats(t_namstat *n1, t_namstat *n2);
int			cmp_mtime_namstats(t_namstat *n1, t_namstat *n2);
t_namstat	**getdir_namstats(const char *path);
void		iterdir_namstats(t_namstat **nst, t_options *opt);
void		free_namstats(t_namstat **nst);
t_namstat	*get_namstat(const char *path);
void		print_namstats(t_namstat **nst, const t_options *opt);
void		process_namstats(t_namstat **nst, const t_options *opt);
void		recurse_namstats(t_namstat **nst, const t_options *opt);
void		sort_namstats(t_namstat **nst, const t_options *opt);

int		get_options(char ***argv, t_options *opt);

int		is_dir(const char *path);
int		is_file(const char *path);
ssize_t	count_files(const char *path);
char	*join_path(char *buf, const char *path, const char *name);
char	*get_basename(char *buf, const char *path);
void	free_tab(char **tab);
size_t	len_tab(char **tab);
void	sort_tab(char **tab);

#endif
