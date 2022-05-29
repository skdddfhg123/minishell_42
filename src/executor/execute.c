/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 04:58:07 by dongmlee          #+#    #+#             */
/*   Updated: 2022/05/29 23:36:48 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_built_in(char *cmd)
{
	if (!ft_strncmp("echo", cmd, 5) || !ft_strncmp("pwd", cmd, 4) || \
	!ft_strncmp("export", cmd, 6) || !ft_strncmp("unset", cmd, 6) || \
	!ft_strncmp("env", cmd, 4) || !ft_strncmp("exit", cmd, 5) || \
	!ft_strncmp("cd", cmd, 3))
		return (1);
	return (0);
}

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

int	use_pipe(t_cmd *cmds, int *pipe_open)
{
	if (cmds->pipe)
	{
		*pipe_open = 1;
		if (pipe(cmds->pipes) == -1)
			return (-1);
	}
	else
		*pipe_open = 0;
	return (1);
}

void	get_cmd_handler(t_cmd *cmds, char *cmd_cpy)
{
	(void)cmd_cpy;
	cmds->cmd = get_val_cmd(cmds);
	if (!cmds->cmd)
		; // error
}

static int	child_handler(t_cmd *cmds, int flag)
{
	signal(SIGQUIT, SIG_DFL);
	(void)flag;
	// if (command->input || command->output)
	// {
	// 	if (redirection_handler(command) == ERROR)
	// 		return (ERROR);
	// }
	// if (command->is_pipe && !command->output)
	// {
	// 	if (dup2(command->pipe[WRITE], WRITE) == ERROR)
	// 		return (ERROR);
	// }
	// if (command->prev && command->prev->is_pipe && !command->input)
	// {
	// 	if (dup2(command->prev->pipe[READ], READ) == ERROR)
	// 		return (ERROR);
	// }
	// if (flag)
	// 	exec_built_in(command, flag);
	if (execve(cmds->cmd, cmds->args, g_state.envp) == -1)
		return (-1);
	return (1);
}

void	parent_handler(t_cmd *cmds, pid_t pid, int pipe_open)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (status == SIGINT)
		printf("\n");
	else if (status == SIGQUIT)
		printf("Quit: %d\n", status);
	if (pipe_open)
	{
		close(cmds->pipes[1]);
		if (!cmds->next)
			close(cmds->pipes[0]);
	}
	// if (cmds->prev && cmds->prev->is_pipe)
	// 	close(cmds->prev->pipe[0]);
	signal_handle();
	g_state.exit_status = *(int *)&status >> 8 & 0x000000ff;
}

static int	exec_cmd(t_cmd *cmds, int flag)
{
	pid_t	pid;
	int		pipe_open;

	if (use_pipe(cmds, &pipe_open) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (!pid)
	{
		if (child_handler(cmds, flag) == -1)
			exit(1);
	}
	else
		parent_handler(cmds, pid, pipe_open);
	return (1);
}

int	execute_cmds(t_cmd *cmds)
{
	int		flag;
	char	*cmd_cpy;

	while (cmds)
	{
		cmd_cpy = cmds->cmd;
		flag = is_built_in(cmds->cmd);
		if (!flag)
			get_cmd_handler(cmds, cmd_cpy);
		if (cmds->cmd)
		{
			exec_cmd(cmds, flag);
			break ;
		}
		break ;
	}
	return (1);
}
