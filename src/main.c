/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 02:00:43 by dongmlee          #+#    #+#             */
/*   Updated: 2022/05/30 00:20:26 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>

static void	get_paths(void)
{
	char	*path;
	char	**paths;
	int		i;

	path = get_env("PATH");
	paths = ft_split(path, ':');
	if (!paths)
		return ;
	i = 0;
	while (paths[i])
		i++;
	g_state.safe_paths = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = path;
		g_state.safe_paths[i] = paths[i];
		i++;
	}
	for (int i = 0; g_state.safe_paths[i]; i++)
		printf("%d %s\n",i,  g_state.safe_paths[i]);
	g_state.safe_paths[i] = NULL;
	free(paths);
}

static int	routine(t_cmd	*cmds)
{
	while (1)
	{
		cmds->cmd = readline("minishell$ ");
		if (!cmds->cmd)
			return (1);
		if (cmds->cmd[0] != '\0')
			add_history(cmds->cmd);
		execute_cmds(cmds);
		// ft_format_path(cmds);
		// if (cmds->cmd[0] != '\0')	
		// 	add_history(cmds->cmd);
		// if (cmds_process_loop(cmd))
		// 	break ;
		free(cmds->cmd);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd			cmds;

	(void)argc;
	(void)argv;
	copy_env(envp);
	get_paths();
	signal_handle();
	routine(&cmds);
	ft_free_two_ptr(g_state.env_str);
	g_state.exit_status = 130;
	printf("exit\n");
	return (g_state.exit_status);
}
