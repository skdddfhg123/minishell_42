/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:33:26 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:26:13 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isset(char c, char const *set)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	size_t		s_point;
	size_t		e_point;
	size_t		i;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	e_point = ft_strlen(s1);
	s_point = 0;
	while (s_point < e_point && ft_isset(s1[s_point], set))
		s_point++;
	while (s_point < e_point && ft_isset(s1[e_point - 1], set))
		e_point--;
	res = (char *)malloc(sizeof(char) * (e_point - s_point + 1));
	if (!res)
		return (0);
	i = 0;
	while (s_point < e_point)
		res[i++] = s1[s_point++];
	res[i] = 0;
	return (res);
}
