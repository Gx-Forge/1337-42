
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp_lst;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp_lst = *lst;
	while (tmp_lst->next != NULL)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = new;
}
