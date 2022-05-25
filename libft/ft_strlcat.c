/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:30:44 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:25:54 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	result;
	size_t	i;

	dst_len = ft_strlen(dst);
	result = ft_strlen(src);
	i = 0;
	while (src[i] && i + dst_len + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dstsize < dst_len)
		result += dstsize;
	else
	{
		result += dst_len;
		dst[dst_len + i] = 0;
	}
	return (result);
}
