/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:20:38 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 15:58:16 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_foreward(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;

	lst = smollest_cost(stack_a);
	optimization(stack_a, stack_b, lst);
	while ((*stack_a) != lst)
	{
		if ((ft_lstsize(*stack_a) / 2) >= lst->index)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	while ((*stack_b) != lst->target)
	{
		if ((ft_lstsize(*stack_b) / 2) >= lst->target->index)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
	ft_pb(stack_a, stack_b);
}

void	optimization(t_list **stack_a, t_list **stack_b, t_list *lst)
{
	if ((ft_lstsize(*stack_a) - lst->index)
		== (ft_lstsize(*stack_b) - lst->target->index))
	{
		while ((*stack_a != lst) && (*stack_b != lst->target))
		{
			if ((ft_lstsize(*stack_a) / 2) >= lst->index)
				ft_rr(stack_a, stack_b);
			else
				ft_rrr(stack_a, stack_b);
		}
	}
	while (((*stack_a) != lst) && ((*stack_b) != lst->target))
	{
		if (((ft_lstsize(*stack_a) / 2) >= lst->index)
			&& ((ft_lstsize(*stack_b) / 2) >= lst->target->index))
			ft_rr(stack_a, stack_b);
		else if (((ft_lstsize(*stack_a) / 2) < lst->index)
			&& ((ft_lstsize(*stack_b) / 2) < lst->target->index))
			ft_rrr(stack_a, stack_b);
		else
			break ;
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 3)
	{
		ft_index(stack_a);
		ft_index(stack_b);
		target_of_node(stack_a, stack_b);
		cost(stack_a, stack_b);
		push_foreward(stack_a, stack_b);
	}
	ft_sort_3num(stack_a);
	push_back(stack_a, stack_b);
	ft_index(stack_a);
	lst = _find_smollest_num(*stack_a);
	while (((*stack_a)->index) != lst->index)
	{
		if ((ft_lstsize(*stack_a) / 2) >= lst->index)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}
