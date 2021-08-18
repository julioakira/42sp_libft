/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 04:59:52 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/18 01:05:51 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return;
	new->next = *lst;
	*lst = new;
}

// (*lst)->content
// *lst->content
void ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		(*lst) = (*lst)->next;
	}
	*lst = NULL;
}

int main(void)
{
	t_list * l =  ft_lstnew(malloc(1));
	for (int i = 0; i < 10; ++i)
		ft_lstadd_front(&l, ft_lstnew(malloc(1)));
	printf("Value of l: %p\n", l);
	ft_lstclear(&l, free);
	printf("Value of l after: %p\n", l);
}
