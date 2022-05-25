/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 02:49:54 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:25:12 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*last_lst;

	cnt = 0;
	last_lst = lst;
	if (!lst)
		return (0);
	while (last_lst->next)
	{
		last_lst = last_lst->next;
		cnt++;
	}
	if (!last_lst->next)
		cnt++;
	return (cnt);
}
