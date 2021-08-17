/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 04:59:52 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/17 05:14:07 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		// Deletar cada node da linked list
		// Free no *lst;
	}
}
