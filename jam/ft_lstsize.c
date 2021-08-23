/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 03:40:55 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/17 02:12:51 by jakira-p         ###   ########.fr       */
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

int ft_lstsize(t_list *lst)
{
	int size;
	t_list *tmp;

	if (!lst)
		return (0);
	size = 0;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		size++;
	}
	if (tmp->next == NULL)
		size++;
	return (size);
}

int main(void)
{
	t_list *lst = NULL;
	void *content = (void *)10;
	void *content2 = (void *)500;
	printf("lst size initial: %d\n", ft_lstsize(lst));
	ft_lstadd_front(&lst, ft_lstnew(content));
	printf("lst size after add one: %d\n", ft_lstsize(lst));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	printf("lst size after add two: %d\n", ft_lstsize(lst));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	ft_lstadd_front(&lst, ft_lstnew(content2));
	printf("lst size final boss: %d\n", ft_lstsize(lst));
}
