/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:14:31 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/18 02:37:30 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		prev = *lst;
		(*lst) = prev->next;
		del(prev);
	}
	*lst = NULL;
}
