#include "push_swap.h"

void	ft_swap_list(t_list **head)
{
	t_list	last;

	if (!head)
		return;
	if (ft_lstsize(*head) == 1)
		return;
	last = *head;
	*head = last->next;
	last->next = *head->next;
	*head->next = last;
}

void	ft_sa(t_list **stack_a)
{
	ft_swap_list(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	ft_swap_list(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap_list(stack_a);
	ft_swap_list(stack_b);
	write(1, "ss\n", 3);
}
