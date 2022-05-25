/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:12:21 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:24:20 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_over_range(unsigned long long result, int n_check)
{
	if (result > LLONG_MAX - 1 && n_check == -1)
		return (0);
	if (result > LLONG_MAX && n_check == 1)
		return (-1);
	return (result * n_check);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					n_check;
	unsigned long long	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	n_check = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n_check *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (check_over_range(result, n_check));
}
