/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:12:02 by idongmin          #+#    #+#             */
/*   Updated: 2022/06/05 05:24:05 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	input(char *filename, int dup_fd)
{
	char	*err_str;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		err_str = strerror(errno);
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(err_str, 2);
		exit(1);
	}
	dup2(fd, dup_fd);
	close(fd);
}

void	output(char *filename, int dup_fd, int flag)
{
	char	*err_str;
	int		fd;

	if (!flag)
		fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	else
		fd = open(filename, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd < 0)
	{
		err_str = strerror(errno);
		ft_putstr_fd("bash: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(err_str, 2);
		exit(1);
	}
	dup2(fd, dup_fd);
	close(fd);
}

void	here_doc(int index, int dup_fd, t_list *heredoc)
{
	t_list		*iter;
	t_heredoc	*h_iter;
	int			fd;
	int			i;

	i = 0;
	iter = heredoc;
	while (++i < index)
		iter = iter->next;
	h_iter = (t_heredoc *)iter->content;
	fd = open(h_iter->file_name, O_RDWR, 0644);
	if (fd < 0)
		return ;
	dup2(fd, dup_fd);
	close(fd);
}
