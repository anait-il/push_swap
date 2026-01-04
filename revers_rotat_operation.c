#include "push_swap.h"

void	revers_rotat_list(t_list **head)
{
	t_list	*lst;
	t_list	*tmp;

	if (!head || !*head)
		return;
	lst = *head;
	tmp = *head;
	while (lst)
	{
		if (lst->next->next == NULL)
		{	
			break;
		}
		lst = lst->next;
	}
	*head = ft_lstlast(*head);
	(*head)->next = tmp;
	lst->next = NULL;
}

void	ft_rra(t_list **stack_a)
{
	revers_rotat_list(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	revers_rotat_list(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	revers_rotat_list(stack_a);
	revers_rotat_list(stack_b);
	write(1, "rrr\n", 4);
}