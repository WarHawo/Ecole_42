#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**temp;

	if ((*lst) != 0 && del)
	{
		while ((*lst) != 0)
		{
			temp = lst;
			(*del)((*lst)->content);
			free(*lst);
			*lst = (*temp)->next;
		}
	}
	else
		return ;
}