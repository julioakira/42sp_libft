/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 01:40:07 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/18 01:53:55 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_cpy;
	if (!lst || !f || !del)
		return (NULL);
	lst_cpy = malloc(sizeof(lst));
	while (lst_cpy)
	{
		f(lst_cpy->content);
		lst_cpy = lst_cpy->next;
	}
	return (lst_cpy);
}
