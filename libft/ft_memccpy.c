/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:43:29 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:25:15 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	data;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)d;
	src_ptr = (unsigned char *)s;
	data = (unsigned char)c;
	i = 0;
	if (dst_ptr == 0 && src_ptr == 0)
		return (0);
	while (i < n)
	{
		if (src_ptr[i] == data)
		{
			dst_ptr[i] = src_ptr[i];
			return (&dst_ptr[i + 1]);
		}
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (0);
}
