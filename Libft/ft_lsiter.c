#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*list;

	if (lst == NULL)
		return ;
	list = lst;
	while (list != NULL)
	{
		f(list->content);
		list = list->next;
	}
}