
#include "libft.h"

static t_list	*free_list(t_list *first_node, void (*del)(void *))
{
	t_list	*to_free;

	while (first_node != NULL)
	{
		to_free = first_node->next;
		del(first_node->content);
		free(first_node);
		first_node = to_free;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_node;

	if (lst == NULL)
		return (NULL);
	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = f(lst->content);
	new_lst->next = NULL;
	first_node = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		new_lst->next = malloc(sizeof(t_list));
		if (!new_lst->next)
			return (free_list(first_node, del));
		new_lst = new_lst->next;
		new_lst->content = f(lst->content);
		new_lst->next = NULL;
		lst = lst->next;
	}
	return (first_node);
}
