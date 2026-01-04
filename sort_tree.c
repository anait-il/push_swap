#include "push_swap.h"

void	ft_sort_3num(t_list **stack_a)
{
	if ((*stack_a)->content >(*stack_a)->next->content)
		ft_sa((stack_a));
	if ((*stack_a)->content >(*stack_a)->next->next->content)
		ft_rra((stack_a));
	if ((*stack_a)->next->content >(*stack_a)->next->next->content)
	{
		ft_rra((stack_a));
		ft_sa((stack_a));
	}
}
