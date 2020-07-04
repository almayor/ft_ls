/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_namstat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:07:38 by unite             #+#    #+#             */
/*   Updated: 2020/07/04 10:45:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*const g_fg_escape[128] = {
	['a'] = FG_BLK,
	['b'] = FG_RED,
	['c'] = FG_GRN,
	['d'] = FG_BRN,
	['e'] = FG_BLU,
	['f'] = FG_MAG,
	['g'] = FG_CYN,
	['h'] = FG_LGR,
	['A'] = FG_BBLK,
	['B'] = FG_BRED,
	['C'] = FG_BGRN,
	['D'] = FG_BBRN,
	['E'] = FG_BBLU,
	['F'] = FG_BMAG,
	['G'] = FG_BCYN,
	['H'] = FG_BLGR,
	['x'] = FG_DEF,
};

static char	*const g_bg_escape[128] = {
	['a'] = BG_BLK,
	['b'] = BG_RED,
	['c'] = BG_GRN,
	['d'] = BG_BRN,
	['e'] = BG_BLU,
	['f'] = BG_MAG,
	['g'] = BG_CYN,
	['h'] = BG_LGR,
	['A'] = BG_BBLK,
	['B'] = BG_BRED,
	['C'] = BG_BGRN,
	['D'] = BG_BBRN,
	['E'] = BG_BBLU,
	['F'] = BG_BMAG,
	['G'] = BG_BCYN,
	['H'] = BG_BLGR,
	['x'] = BG_DEF,
};

static int	(*const g_color_type[])(t_namstat *nst) = {
	&is_dir_nwoth_namstat,
	&is_lnk_namstat,
	&is_sock_namstat,
	&is_fifo_namstat,
	&is_exe_nuid_ngid_namstat,
	&is_blk_namstat,
	&is_chr_namstat,
	&is_exe_uid_namstat,
	&is_exe_nuid_gid_namstat,
	&is_dir_woth_sticky_namstat,
	&is_dir_namstat,
};

char		*get_color_namstat(t_namstat *nst)
{
	static char	escape_seq[21];
	size_t		i;

	if (!g_opt.gg)
		return ("");
	i = 0;
	while (i < 11)
	{
		if (g_color_type[i](nst))
		{
			escape_seq[0] = '\0';
			ft_strcat(escape_seq, g_fg_escape[g_env.lscolors[2 * i]]);
			ft_strcat(escape_seq, g_bg_escape[g_env.lscolors[2 * i + 1]]);
			return (escape_seq);
		}
		i++;
	}
	return ("");
}

char		*get_reset_color_namstat(t_namstat *nst)
{
	static char	escape_seq[21];

	escape_seq[0] = '\0';
	if (g_opt.gg)
		ft_sprintf(escape_seq, "%s%s", BG_DEF, FG_DEF);
	return (escape_seq);
}
