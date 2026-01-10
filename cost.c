/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:10:30 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/10 13:03:03 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*smollest_cost(t_list **stack_a)
{
	t_list	*lst;
	t_list	*tmp;
	size_t	cost;

	lst = *stack_a;
	tmp = *stack_a;
	while (lst)
	{
		if (lst->cost < tmp->cost)
		{
			tmp = lst;
		}
		lst = lst->next;
	}
	return (tmp);
}

void	cost(t_list **stack_a, t_list **stack_b)
{
	size_t	b_cost;
	size_t	a_cost;
	t_list	*lst;
	t_list	*node;

	if (!*stack_b || !stack_b)
		return ;
	lst = *stack_a;
	node = *stack_b;
	while (lst)
	{
		if ((lst->index <= ft_lstsize(*stack_a) / 2) && (lst->target->index <= ft_lstsize(*stack_b) / 2))
		{
			a_cost = lst->index;
			b_cost = lst->target->index;
			if (a_cost > b_cost)
				lst->cost = a_cost;
			else
				lst->cost = b_cost;
		}
		else if ((lst->index > ft_lstsize(*stack_a) / 2) && (lst->target->index > ft_lstsize(*stack_b) / 2))
		{
			a_cost = ft_lstsize(*stack_a) - lst->index;
			b_cost = ft_lstsize(*stack_b) - lst->target->index;
			if (a_cost > b_cost)
				lst->cost = a_cost;
			else
				lst->cost = b_cost;
		}
		else
		{
			if (lst->index <= ft_lstsize(*stack_a) / 2)
				a_cost = lst->index;
			else
				a_cost = ft_lstsize(*stack_a) - (lst->index);
			if (lst->target->index <= ft_lstsize(*stack_b) / 2)
				b_cost = lst->target->index;
			else
				b_cost = ft_lstsize(*stack_b) - (lst->target->index);
			lst->cost = a_cost + b_cost;
		}
		lst = lst->next;
	}
}
