/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 03:18:31 by dongmlee          #+#    #+#             */
/*   Updated: 2022/04/28 17:24:56 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	tmp_lst = *lst;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		*lst = tmp_lst->next;
		del(tmp_lst->content);
		free(tmp_lst);
		tmp_lst = *lst;
	}
}
