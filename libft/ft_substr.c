/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:42:37 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:26:16 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_size;
	size_t	i;
	size_t	real_len;

	if (s == 0)
		return (0);
	real_len = len;
	s_size = ft_strlen(s);
	if (len > s_size)
		real_len = s_size;
	res = ((char *)malloc(sizeof(char) * (real_len + 1)));
	if (!res)
		return (0);
	if (s_size <= start)
	{
		res[0] = 0;
		return (res);
	}
	i = 0;
	while (real_len--)
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}
