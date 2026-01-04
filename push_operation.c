#include "push_swap.h"

void	push_list(t_list **dest, t_list **src)
{
	t_list	*lst;

	if (!src || !*src)
		return;
	lst = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = lst;
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	push_list(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	push_list(stack_b, stack_a);
	write(1, "pb\n", 3);
}
