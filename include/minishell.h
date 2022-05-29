/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:09:21 by idongmin          #+#    #+#             */
/*   Updated: 2022/05/29 23:43:06 by dongmlee         ###   ########.fr       */
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
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "../libft/libft.h"

typedef struct s_state
{
	char	**envp;
	char	**env_str;
	char	**safe_paths;
	char	*pwd;
	char	*oldpwd;
	int		exit_status;
}	t_state;

typedef struct s_pipe
{
	int				pipes[2];
	struct s_pipe	*next;
	struct s_pipe	*previous;
}	t_pipe;

typedef struct s_cmd
{
	char			**args;
	char			*cmd;
	int				length;
	int				type;
	char			pipe;
	int				pipes[2];
	// t_pipe			*pipes;
	struct s_cmd	*next;
	struct s_cmd	*prev;
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