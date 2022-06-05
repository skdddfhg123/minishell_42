/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 02:07:33 by dongmlee          #+#    #+#             */
/*   Updated: 2022/06/05 05:22:58 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
1. 명령어 중에 "<<" 있는 지 찾기
2. 있을 경우 해당 문자열에 맞는 파일 생성하기
3. here구조체 안에 종료 조건 문자열 길이, 종료 조건 문자열, 인덱스 넣기
*/
static void	prompt_heredoc(int fd, char *end)
{
	char	*str;

	while (1)
	{
		str = readline(">");
		dup2(200, 0);
		if (str == NULL)
		{
			close(fd);
			break ;
		}
		else if (*str == '\0')
			ft_putendl_fd("", fd);
		else if (!ft_strncmp(str, end, ft_strlen(end) + 1))
		{
			free(str);
			break ;
		}
		else
			ft_putendl_fd(str, fd);
		free(str);
	}
}

static void	heredoc_sig_handler(void)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		dup2(0, 200);
		close(0);
		g_state.exit_status = 1;
		g_state.signal = 1;
	}
}

static void	heredoc_signal(void)
{
	struct termios	term;

	signal(SIGINT, heredoc_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	run_heredoc(t_list *iter)
{
	t_heredox	*h_iter;
	int			fd;

	heredoc_signal();
	while (iter && g_state.signal != 1)
	{
		h_iter = (t_heredoc *)iter->content;
		fd = open(h_iter->file_name, O_CREAT | O_TRUNC | O_RDWR | 0644);
		if (fd < 0)
		{
			ft_putendl_fd("can't open file", 2);
			return (0);
		}
		prompt_heredoc(fd, h_iter->end_string);
		close(fd);
		iter = iter->next;
	}
	return (1);
}
