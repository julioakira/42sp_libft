/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:21:57 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/18 01:38:43 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
// #1. The adress of a pointer to an element.
// #2. The adress of the function used to iterate on the list.

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

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;
	if (!new)
		return ;
	last_node = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void addOne(void * p) {++*(int*)p;}

int main(void)
{
	int tab[] = {0, 1, 2, 3};
	t_list * l =  ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	ft_lstiter(l, addOne);
	t_list * tmp = l;
	for (int i = 0; i < 4; i++)
	{
		printf("tmp content: %d\n", *(int *)tmp->content == i + 1);
		tmp = tmp->next;
	}
}
