
#include "list.h"

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	i;
	t_list	*start;

	start = lst;
	while (lst && lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			i = lst->data;
			lst->data = lst->next->data;
			lst->next->data = i;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return (start);
}
