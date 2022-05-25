/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:22:07 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:26:10 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	data;
	int				i;

	i = 0;
	data = (unsigned char)c;
	while (s[i])
	{
		i++;
	}
	if (s[i] == data && data == '\0')
		return ((char *)&s[i]);
	i--;
	while (i >= 0)
	{
		if (s[i] == data)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (0);
}
