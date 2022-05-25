/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:00:30 by dongmlee          #+#    #+#             */
/*   Updated: 2022/05/26 02:12:10 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	copy_env(char **envp)
{
	int	i;

	if (*envp != NULL)
	{
		g_state.envp = envp;
		i = -1;
		while (envp[++i])
			i++;
		g_state.env_str = (char **)malloc(sizeof(char *) * (i + 1));
		i = -1;
		while (envp[++i])
			g_state.env_str[i] = ft_strdup(envp[i]);
		g_state.env_str[i] = NULL;
		i = -1;
		while (envp[++i])
			printf("i = %d ||  %s\n", i, g_state.env_str[i]);
		g_state.pwd = get_env("PWD");
		g_state.oldpwd = get_env("OLDPWD");
		printf("pwd = %s\noldpwd = %s\n", g_state.pwd, g_state.oldpwd);
	}
	return ;
}

char	*get_env(char *key)
{
	int		i;

	if (ft_strlen(key) == 0)
		return (ft_strdup(""));
	i = -1;
	while (g_state.env_str[++i])
	{
		if (!ft_strncmp(g_state.env_str[i], key, ft_strlen(key)))
			return (ft_substr(g_state.env_str[i], ft_strlen(key) + 1, \
			ft_strlen(g_state.env_str[i]) - ft_strlen(key) + 1));
	}
	return (ft_strdup(""));
}
