/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 20:08:53 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/17 01:33:50 by jakira-p         ###   ########.fr       */
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

int main(void)
{
	t_list *lst = NULL;
	t_list *lst2 = NULL;
	void *content1 = (void *)500;
	void *content2 = (void *)10;
	ft_lstadd_front(&lst, ft_lstnew(content1));
	printf("lst->content: %p\n", lst->content);
	printf("lst->next: %p\n", lst->next);
	ft_lstadd_front(&lst2, ft_lstnew(content2));
	printf("lst->content: %p\n", lst2->content);
	printf("lst->next: %p\n", lst2->next);
}
