/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpapadak <fpapadak@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:12:26 by fpapadak          #+#    #+#             */
/*   Updated: 2024/09/23 14:37:02 by fpapadak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%p -> ", (void *)lst);
		printf("%d\n", *(int *)(lst->content));
		lst = lst->next;
	}
}

int	main(void)
{
	int value1 = 42;
	int value2 = 24;

	t_list *lst = NULL;
	t_list *node1 = ft_lstnew(&value1);
	t_list *node2 = ft_lstnew(&value2);
	ft_lstadd_front(&lst, node2);
	ft_lstadd_front(&lst, node1);
	printf("Linked List after adding elements to the front:\n");
	print_list(lst);
	return (0);
}*/
