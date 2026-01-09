/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:09:05 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/09 11:31:33 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*_find_smollest_num(t_list *stack_a)
{
	t_list	*lst;
	t_list	*tmp;

	lst = stack_a;
	tmp = stack_a;
	while (lst)
	{
		if (lst->content < tmp->content)
		{
			tmp = lst;
			lst = lst->next;
		}
		else
			lst = lst->next;
	}
	return (tmp);
}

void	ft_sort_four_and_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*rank;
	size_t	size;

	size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) != 3)
	{
		ft_index(stack_a);
		rank = _find_smollest_num(*stack_a);
		if (rank->index > (size / 2))
		{
			while ((*stack_a)->index != rank->index)
				ft_rra(stack_a);
		}
		else
		{
			while ((*stack_a)->index != rank->index)
				ft_ra(stack_a);
		}
		ft_pb(stack_a, stack_b);
	}
	ft_sort_3num(stack_a);
	while (ft_lstsize(*stack_b))
		ft_pa(stack_a, stack_b);
}
