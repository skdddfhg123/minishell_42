/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 02:57:39 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:25:03 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_lst;

	last_lst = lst;
	if (!lst)
		return (0);
	while (last_lst->next)
	{
		last_lst = last_lst->next;
	}
	return (last_lst);
}
