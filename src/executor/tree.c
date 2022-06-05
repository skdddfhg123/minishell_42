/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 05:26:52 by idongmin          #+#    #+#             */
/*   Updated: 2022/06/05 05:27:19 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	tree_traversal(t_node *tree, t_cmds *data, \
int pipe_exist, t_list *heredoc)
{
	if (!tree)
	{
		dup2(254, 0);
		dup2(255, 1);
		close(254);
		close(255);
		return ;
	}
	if (tree->type == TYPE_IN_OVERWRITE)
		input(tree->right->file_name, 0);
	else if (tree->type == TYPE_OUT_OVERWRITE)
		output(tree->right->file_name, 1);
	else if (tree->type == TYPE_HEREDOC)
		here_doc(tree->right->heredoc_idx, 0, heredoc);
	else if (tree->type == TYPE_OUT_APPEND)
		output_append(tree->right->file_name, 1);
	else if (tree->type == TYPE_CMD)
	{
		if (!pipe_exist)
			select_cmd(data);
		else
			select_multiple_cmd(data);
	}
	tree_traversal(tree->left, data, pipe_exist, heredoc);
}
