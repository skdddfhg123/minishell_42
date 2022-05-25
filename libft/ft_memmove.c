/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:29:53 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:25:26 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (dst == src || !len)
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	if (dst < src)
		ft_memcpy(dst_p, src_p, len);
	else
	{
		dst_p += len;
		src_p += len;
		while (len--)
			*--dst_p = *--src_p;
	}
	return (dst);
}
