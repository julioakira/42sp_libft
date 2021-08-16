/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 04:03:30 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/16 04:41:28 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;
	if (!lst || !new)
		return ;
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
