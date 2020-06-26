/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:26:07 by unite             #+#    #+#             */
/*   Updated: 2020/06/27 01:31:56 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	init_paths(char **paths, t_namstat **regs, t_namstat **dirs)
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
		paths++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_namstat	**regs;
	t_namstat	**dirs;

	if (get_options(&argv))
		return (1);
	dirs = 0;
	if ((!*argv && !(regs = getdir_namstats("."))) ||
		(*argv && (
			!(regs = ft_calloc(sizeof(t_namstat *), argc)) ||
			!(dirs = ft_calloc(sizeof(t_namstat *), argc)) ||
			init_paths(argv, regs, dirs))))
		perrror();
	else
	{
		process_namstats(regs);
		if (dirs && *regs && *dirs)
			ft_putstr("\n");
		iterdir_namstats(dirs);
	}
	free_namstats(regs);
	free_namstats(dirs);
	return (errno);
}
