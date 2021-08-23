/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:20:30 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/17 00:22:58 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

int main(void)
{
	void	*content = (void *)500;
	void	*content2 = (void *)10;
	t_list	*lst = ft_lstnew(content);
	t_list	*lst2 = ft_lstnew(content2);
	printf("Content: %p\n", lst->content);
	printf("Content2: %p\n", lst2->content);
}
