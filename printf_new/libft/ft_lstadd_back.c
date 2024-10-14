/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:15:57 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/24 10:54:19 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		i = *lst;
		while (i->next)
			i = i->next;
		i->next = new;
	}
}
/*
#include <stdio.h>

void print_list(t_list *lst)
{
    while (lst)
   	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list *node1 = ft_lstnew("First");
	t_list *node2 = ft_lstnew("Second");
	t_list *node3 = ft_lstnew("Third");

	node1->next = node2;
	node2->next = node3;

	print_list(node1);
	t_list *node4 = ft_lstnew("Fourth");
	ft_lstadd_back(&node1, node4);
	print_list(node1);
}*/
