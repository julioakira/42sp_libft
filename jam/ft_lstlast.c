/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 03:45:45 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/17 04:30:44 by jakira-p         ###   ########.fr       */
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

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int main(void)
{
	t_list	*lst = NULL;
	void	*content = (void *)10;
	void	*content2 = (void *)500;
	void	*content3 = (void *)256;
	printf("lst before %p\n", ft_lstlast(lst));
	ft_lstadd_back(&lst, ft_lstnew(content));
	printf("lst after content %p\n", ft_lstlast(lst)->content);
	ft_lstadd_back(&lst, ft_lstnew(content2));
	printf("lst after content two %p\n", ft_lstlast(lst)->content);
	ft_lstadd_back(&lst, ft_lstnew(content3));
	printf("lst after content three %p\n", ft_lstlast(lst)->content);

}
