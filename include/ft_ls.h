/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:24:40 by unite             #+#    #+#             */
/*   Updated: 2020/06/26 05:27:42 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <limits.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include "libftprintfgnl.h"
#include "color_escape_codes.h"

# define OPTIONS	"@AFGPRSadelmrt1"

typedef struct	s_options
{
	int			at;
	int			A;
	int			F;
	int			G;
	int			P;
	int			R;
	int			S;
	int			a;
	int			d;
	int			e;
	int			l;
	int			m;
	int			r;
	int			t;
	int			_1;
}				t_options;

t_options		g_opt;

int				get_options(char ***argv);
void			set_option_at();
void			set_option_1();
void			set_option_A();
void			set_option_F();
void			set_option_G();
void			set_option_P();
void			set_option_R();
void			set_option_S();
void			set_option_a();
void			set_option_d();
void			set_option_e();
void			set_option_l();
void			set_option_m();
void			set_option_r();
void			set_option_t();
void			set_options_env();

typedef struct	s_namstat
{
	char		path[PATH_MAX + 1];
	char		base[NAME_MAX + 2];
	struct stat	stat;
}				t_namstat;

int				cmp_alnum_namstats(t_namstat *n1, t_namstat *n2);
int				cmp_mtime_namstats(t_namstat *n1, t_namstat *n2);
int				cmp_size_namstats(t_namstat *n1, t_namstat *n2);
t_namstat		**getdir_namstats(const char *path);
void			iterdir_namstats(t_namstat **nst);
void			free_namstats(t_namstat **nst);
t_namstat		*get_namstat(const char *path);
void			process_namstats(t_namstat **nst);
void			recurse_namstats(t_namstat **nst);
void			sort_namstats(t_namstat **nst);

char			*get_color_namstat(t_namstat *nst);
char			*get_suffix_namstat(t_namstat *nst);
void			print_namstats(t_namstat **nst);

ssize_t			count_files(const char *path);
char			*join_path(char *buf, const char *path, const char *name);
char			*get_basename(char *buf, const char *path);
void			free_tab(char **tab);
size_t			len_tab(char **tab);
void			sort_tab(char **tab);

int				is_blk_namstat(t_namstat *nst);
int				is_chr_namstat(t_namstat *nst);
int				is_dir_namstat(t_namstat *nst);
int				is_dir_nwoth_namstat(t_namstat *nst);
int				is_dir_woth_nsticky_namstat(t_namstat *nst);
int				is_dir_woth_sticky_namstat(t_namstat *nst);
int				is_exe_namstat(t_namstat *nst);
int				is_exe_nuid_gid_namstat(t_namstat *nst);
int				is_exe_nuid_ngid_namstat(t_namstat *nst);
int				is_exe_uid_namstat(t_namstat *nst);
int				is_fifo_namstat(t_namstat *nst);
int				is_lnk_namstat(t_namstat *nst);
int				is_reg_namstat(t_namstat *nst);
int				is_sock_namstat(t_namstat *nst);
int				is_wht_namstat(t_namstat *nst);

#endif
