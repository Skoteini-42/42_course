/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:46:16 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/24 10:06:41 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *node1 = ft_lstnew("First");
	t_list *node2 = ft_lstnew("Second");
	t_list *node3 = ft_lstnew ("Third");

	node1->next = node2;
	node2->next = node3;
	t_list	*last = ft_lstlast(node1);
	printf("%s", (char *)last->content);
}*/
