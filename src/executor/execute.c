/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 04:58:07 by dongmlee          #+#    #+#             */
/*   Updated: 2022/06/05 18:24:15 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_val_cmd(t_cmd *cmds)
{
	char		*cmd_path;
	int			i;
	struct stat	buf;

	if (stat(cmds->cmd, &buf) == 0)
	{
		if ((buf.st_mode & S_IFMT) == S_IFDIR)
			return (NULL);
		return (cmds->cmd);
	}
	else
	{
		i = -1;
		cmd_path = NULL;
		while (g_state.safe_paths[++i])
		{
			cmd_path = ft_strjoin(g_state.safe_paths[i], cmds->cmd);
			if (stat(cmd_path, &buf) == 0)
				return (cmd_path);
			free(cmd_path);
			cmd_path = NULL;
		}
	}
	return (NULL);
}

static void	execve_error(char *str)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": command not found", 2);
	g_state.exit_status = 127;
	exit (127);
}

static void	execut_cmd(t_cmd *cmds)
{
	char	*path;
	int		pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	eles if (pid == 0)
	{
		path = get_val_cmd(cmds);
		if (execve(path, cmds->cmd_argv, g_state.envp))
			execve_error(cmds->cmd);
	}
	else
	{
		wait(g_state.exit_status);
		g_state.exit_status = WEXITSTATUS(status);
		if (g_state.signal)
			g_state.exit_status = g_state.signal;
	}
}

static void	single_cmd(t_cmd *cmds)
{
	if (!ft_strncmp("pwd", cmds->cmd, 4))
		pirntf("pwd");
	else if (!ft_strncmp("exit", cmds->cmd, 5))
		pirntf("exit");
	else if (!ft_strncmp("echo", cmds->cmd, 5))
		pirntf("echo");
	else if (!ft_strncmp("env", cmds->cmd, 4))
		pirntf("env");
	else if (!ft_strncmp("unset", cmds->cmd, 6))
		pirntf("unset");
	else if (!ft_strncmp("export", cmds->cmd, 6))
		pirntf("export");
	else if (!ft_strncmp("cd", cmds->cmd, 3))
		pirntf("cd");
	else
		execut_cmd(cmds);
}

static void	multi_cmd(t_cmd *cmds)
{
	char	*path;

	if (!ft_strncmp("pwd", cmds->cmd, 4))
		pirntf("pwd");
	else if (!ft_strncmp("exit", cmds->cmd, 5))
		pirntf("exit");
	else if (!ft_strncmp("echo", cmds->cmd, 5))
		pirntf("echo");
	else if (!ft_strncmp("env", cmds->cmd, 4))
		pirntf("env");
	else if (!ft_strncmp("unset", cmds->cmd, 6))
		pirntf("unset");
	else if (!ft_strncmp("export", cmds->cmd, 6))
		pirntf("export");
	else if (!ft_strncmp("cd", cmds->cmd, 3))
		pirntf("cd");
	else
	{
		path = get_val_cmd(cmds);
		if (execve(path, cmds->cmd_argv, g_state.envp))
			execve_error(cmds->cmd);
	}
}
