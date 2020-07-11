/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:26:07 by unite             #+#    #+#             */
/*   Updated: 2020/07/11 18:25:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_options		g_opt;
t_environment	g_env;

static int		init_paths(char **paths, t_namstat **regs, t_namstat **dirs)
{
	t_namstat	*nst;

	if (!g_opt.f)
		sort_tab(paths);
	while (*paths)
	{
		if (!(nst = get_namstat(*paths)))
			ft_dprintf(2, "ft_ls: %s: %s\n", *paths, strerror(errno));
		else if (is_dir_namstat(nst) && !g_opt.d)
			*dirs++ = nst;
		else
			*regs++ = nst;
		errno = 0;
		paths++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_namstat	**regs;
	t_namstat	**dirs;

	if (get_options(&argv) ||
		get_environment())
		return (1);
	if (!*argv)
		argv = (char *[2]){".", 0};
	if (!(regs = ft_calloc(sizeof(t_namstat *), len_tab(argv) + 1)) ||
		!(dirs = ft_calloc(sizeof(t_namstat *), len_tab(argv) + 1)) ||
		init_paths(argv, regs, dirs))
		perror("ft_ls");
	else
	{
		process_namstats(regs);
		if (dirs && *regs && *dirs)
			ft_putstr("\n");
		iterdir_namstats(dirs, len_tab(argv) > 1);
	}
	free_namstats(regs);
	free_namstats(dirs);
	return (errno);
}
