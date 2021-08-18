/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:59:55 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/18 04:07:38 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*safe_lstnew(t_list *lst, void *(f)(void *),
void (*del)(void *))
{
	t_list	*new_node;
	if (!lst || !f || !del)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_node = safe_lstnew(lst, f, del);
	if (!new_node)
		return (NULL);
	new_lst = new_node;
	lst = lst->next;
	while (lst)
	{
		new_node = safe_lstnew(lst, f, del);
		if (!new_node)
			break ;
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}
