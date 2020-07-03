/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namstat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:17:41 by unite             #+#    #+#             */
/*   Updated: 2020/07/03 22:09:04 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMSTAT_H
# define NAMSTAT_H

typedef struct	s_namstat
{
	char		path[PATH_MAX + 1];
	char		base[NAME_MAX + 2];
	struct stat	stat;
}				t_namstat;

/*
** Access
*/

t_namstat		**getdir_namstats(const char *path);
t_namstat		*get_namstat(const char *path);
void			iterdir_namstats(t_namstat **nst, int multi);
void			free_namstats(t_namstat **nst);
size_t			len_namstats(t_namstat **nst);
blkcnt_t		nblocks_namstats(t_namstat	**nst);
void			process_namstats(t_namstat **nst);
void			recurse_namstats(t_namstat **nst);
t_namstat		*get_namstat(const char *path);
t_namstat		**getdir_namstats(const char *path);

/*
** Sorting
*/

void			sort_namstats(t_namstat **nst);
int				cmp_alnum_namstats(t_namstat *n1, t_namstat *n2);
int				cmp_birthtime_namstats(t_namstat *n1, t_namstat *n2);
int				cmp_atime_namstats(t_namstat *n1, t_namstat *n2);
int				cmp_ctime_namstats(t_namstat *n1, t_namstat *n2);
int				cmp_mtime_namstats(t_namstat *n1, t_namstat *n2);
int				cmp_size_namstats(t_namstat *n1, t_namstat *n2);

/*
** Printng
*/

void			print_namstats(t_namstat **nst);
void			print_cols_namstats(t_namstat **nst);
void			print_long_namstats(t_namstat **nst);
void			print_rows_namstats(t_namstat **nst);
void			print_simple_namstats(t_namstat **nst);
void			print_stream_namstats(t_namstat **nst);
char			*get_access_namstat(t_namstat *nst);
char			*get_acl_namstat(t_namstat *nst);
char			*get_color_namstat(t_namstat *nst);
char			*get_reset_color_namstat(t_namstat *nst);
char			*get_group_namstat(t_namstat *nst);
char			*get_ino_namstat(t_namstat *nst);
char			*get_lpath_namstat(t_namstat *nst);
char			*get_name_namstat(t_namstat *nst);
char			*get_nblocks_namstat(t_namstat *path);
char			*get_nlink_namstat(t_namstat *nst);
char			*get_size_dev_namstat(t_namstat *nst);
char			*get_suffix_namstat(t_namstat *nst);
char			*get_time_namstat(t_namstat *nst);
char			*get_user_namstat(t_namstat *nst);
char			*get_xattr_namstat(t_namstat *nst);

/*
** Describing
*/

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
