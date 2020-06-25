/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:26:07 by unite             #+#    #+#             */
/*   Updated: 2020/06/25 08:41:39 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	init_paths(char **paths, t_namstat **regs, t_namstat **dirs)
{
	sort_tab(paths);
	while (*paths)
	{
		if (is_dir(*paths))
		{
			if (!(*dirs++ = get_namstat(*paths)))
				return (1);
		}
		else if (is_file(*paths))
		{
			if (!(*regs++ = get_namstat(*paths)))
				return(1);
		}
		else
			ft_printf("ft_ls: %s: No such file or directory\n", *paths);
		paths++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_options	opt;
	t_namstat	**regs;
	t_namstat	**dirs;

	if (get_options(&argv, &opt))
		return (1);
	regs = 0;
	if ((argc < 2 && !(dirs = getdir_namstats("."))) ||
		(argc >= 2 && (
			!(regs = ft_calloc(sizeof(t_namstat *), argc)) ||
			!(dirs = ft_calloc(sizeof(t_namstat *), argc)) ||
			init_paths(argv, regs, dirs))))
		ft_printf("ft_ls: %s\n", strerror(errno));
	else
	{
		process_namstats(regs, &opt);
		if (regs && *regs && *dirs)
			ft_putstr("\n");
		iterdir_namstats(dirs, &opt);
	}
	free_namstats(regs);
	free_namstats(dirs);
	return (errno);
}
