/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:37:56 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:25:46 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	data;
	int				i;

	i = 0;
	data = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == data)
		{
			return ((char *)&s[i]);
		}
		i++;
		if (s[i] == data && data == '\0')
			return ((char *)&s[i]);
	}
	if (data == '\0')
		return ((char *)&s[i]);
	return (0);
}
