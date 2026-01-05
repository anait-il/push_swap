/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:01:45 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/05 21:30:16 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_100(t_list **stack_a, t_list **stack_b)
{
	size_t	rank;
	size_t	size_a;
	size_t	size_b;
	t_list  *lst;

	lst = *stack_b;
	while (ft_lstsize(*stack_a) != 50)
	{
		ft_pb(stack_a, stack_b);

	}
	while (lst)
	{
		size_a = ft_lstsize(*stack_a);
		size_b = ft_lstsize(lst);
		ft_index(stack_a);
		rank = _find_smollest_num(lst);
		if (rank > (size_b / 2))
		{
			while (lst->index != rank)
				ft_rra(&lst);
		}	
		else
		{
			while (lst->index != rank)
				ft_ra(&lst);
		}
		lst = lst->next;
	}
	while (*stack_b)
	{
		ft_pa(stack_a, stack_b);
	}
	printf("hh\n");
	while (ft_lstsize(*stack_a) != 3)
	{
		size_a = ft_lstsize(*stack_a);
		size_b = ft_lstsize(*stack_b);
		ft_index(stack_a);
		while (ft_lstsize(*stack_a) >= 50)
			ft_pb(stack_a, stack_b);
		rank = _find_smollest_num(*stack_b);
		if (rank > (size_b / 2))
		{
			while ((*stack_b)->index != rank)
				ft_rra(stack_b);
		}	
		else
		{
			while ((*stack_b)->index != rank)
				ft_ra(stack_b);
		}
		ft_pb(stack_a, stack_b);
	}
	ft_sort_3num(stack_a);
	while (ft_lstsize(*stack_b) != 0)
		ft_pa(stack_a, stack_b);
}