/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 02:17:09 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/07 02:20:07 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	idx;
	if (!s)
		return;
	idx = 0;
	while (s[idx])
	{
		write(fd, &s[idx], 1);
		idx++;
	}
	write(fd, "\n", 1);
}

int main(void)
{
	char *str = "Hello, world!";
	ft_putendl_fd(str, 2);
	return (0);
}
