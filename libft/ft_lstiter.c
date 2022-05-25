/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 03:32:08 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:25:00 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*last_lst;

	last_lst = lst;
	if (!lst || !(*f))
		return ;
	while (last_lst)
	{
		(*f)(last_lst->content);
		last_lst = last_lst->next;
	}
}
