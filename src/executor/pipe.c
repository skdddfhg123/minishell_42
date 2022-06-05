/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 03:05:28 by dongmlee          #+#    #+#             */
/*   Updated: 2022/06/05 05:23:10 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pipe_setting(t_list *cmds, t_list *heredoc)
{
	t_cmd	*execl;

	execl = (t_cmd *)cmds->content;
	dup2(0, 254);
	dup2(1, 255);
	if (!cmds->next)
		tree_traversal(execl->root, execl, 0, heredoc);
	else
		fork_pipe(cmds, heredoc);
}

void	change_connection_pipe_parent(t_list *cmd, int *p)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)cmd->content;
	close(p[1]);
	if (cmds->fd != 0)
	{
		dup2(p[0], 3);
		close(p[0]);
	}
}

void	change_connection_pipe_child(t_list *cmd, int *p)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)cmd->content;
	close(p[0]);
	if (cmd->next)
		dup2(p[1], 1);
	close(p[1]);
	if (cmds->fd)
	{
		dup2(cmds->fd, 0);
		close(cmds->fd);
	}
}

void	wait_all_child(t_list *head, int last_pid)
{
	int	pid;

	while (head)
	{
		pid = wait(g_state.exit_status);
		if (pid == last_pid)
		{
			g_state.exit_status = WEXITSTATUS(g_state.exit_status);
			if (g_state.signal)
				g_state.exit_status = g_state.signal;
		}
		head = head->next;
	}
}

void	fork_pipe(t_list *link, t_list *heredoc)
{
	int		pi[2];
	t_list	*head;
	t_cmd	*cmds;

	head = link;
	while (link)
	{
		pipe(pi);
		cmds = (t_cmd *)link->content;
		cmds->pid = fork();
		if (cmds->pid < 0)
			exit(1);
		else if (cmds->pid > 0)
			change_connection_pipe_parent(link, pi);
		else
		{
			change_connection_pipe_child(link, pi);
			tree_traversal(cmds->root, cmds, 1, heredoc);
		}
		if (link->next)
			((t_cmd *)link->next->content)->fd = 3;
		link = link->next;
	}
	close(3);
	wait_all_child(head, cmds->pid);
}
