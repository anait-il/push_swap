#include "push_swap.h"

void	rotate_list(t_list **head)
{
	t_list	*lst;
	t_list	*last_node;

	lst = *head;
	if (!head || !*head)
		return;
	if (ft_lstsize(*head) == 1)
		return;
	*head = lst->next;
	last_node = ft_lstlast(lst);
	last_node->next = lst;
	lst->next = NULL;
}

void	ft_ra(t_list **stack_a)
{
	rotate_list(stack_a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	rotate_list(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_list(stack_a);
	rotate_list(stack_b);
	write(1, "rr\n", 3);
}
