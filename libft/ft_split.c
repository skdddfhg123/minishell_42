/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:43:51 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:25:44 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_issep(char ch, char c)
{
	if (ch == c)
		return (1);
	return (0);
}

static size_t	ft_count_words(char *s, char c)
{
	size_t			cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && ft_issep(*s, c))
			s++;
		if (*s && !ft_issep(*s, c))
		{
			cnt++;
			while (*s && !ft_issep(*s, c))
				s++;
		}
	}
	return (cnt);
}

static void	*ft_mem_free(char **arr, size_t cnt)
{
	size_t			i;

	i = 0;
	while (i < cnt)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static char	*ft_malloc_word(char *s, char c, char **arr, size_t cnt)
{
	char			*word;
	size_t			i;

	i = 0;
	while (s[i] && !ft_issep(s[i], c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
	{
		ft_mem_free(arr, cnt);
		return (s);
	}
	i = 0;
	while (s[i] && !ft_issep(s[i], c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	size_t			word_num;
	size_t			i;

	if (!s)
		return (0);
	word_num = ft_count_words((char *)s, c);
	i = 0;
	arr = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!arr)
		return (0);
	while (*s && i < word_num)
	{
		while (*s && ft_issep(*s, c))
			s++;
		if (*s && !ft_issep(*s, c))
		{
			arr[i] = ft_malloc_word((char *)s, c, arr, i);
			i++;
			while (*s && !ft_issep(*s, c))
				s++;
		}
	}
	arr[i] = 0;
	return (arr);
}
