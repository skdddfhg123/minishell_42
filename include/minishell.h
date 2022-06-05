/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:09:21 by idongmin          #+#    #+#             */
/*   Updated: 2022/06/05 18:24:29 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "../libft/libft.h"

typedef struct s_heredoc
{
	char	*end_string;
	char	*file_name;
}	t_heredoc;

typedef struct s_node
{
	t_node_type		type;
	char			*file_name;
	int				heredoc_idx;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef enum e_node_type
{
	TYPE_IN_OVERWRITE,
	TYPE_OUT_OVERWRITE,
	TYPE_HEREDOC,
	TYPE_OUT_APPEND,
	TYPE_CMD,
	TYPE_ETC
}	t_node_type;

typedef struct s_state
{
	char	**envp;
	char	**env_str;
	char	**safe_paths;
	char	*pwd;
	char	*oldpwd;
	int		exit_status;
	int		signal;
}	t_state;

typedef struct s_cmd
{
	char			**args;
	char			*cmd_path;
	char			*cmd;
	int				length;
	int				type;
	char			pipe;
	int				pid;
	int				fd;
	t_node			*root;
}					t_cmd;

t_state	g_state;

/* 
	env
*/
void	copy_env(char **envp);
char	*get_env(char *key);

/*
	executor
*/
int		execute_cmds(t_cmd *cmds);
void	parent_handler(t_cmd *cmds, pid_t pid, int pipe_open);
void	get_cmd_handler(t_cmd *cmds, char *cmd_cpy);
int		use_pipe(t_cmd *cmds, int *pipe_open);
char	*get_val_cmd(t_cmd *cmds);
int		is_built_in(char *cmd);

/*
	util
*/
void	signal_handle(void);
void	ft_free_two_ptr(char **ptr);

#endif