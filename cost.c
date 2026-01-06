/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:10:30 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/06 22:39:27 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smollest_cost(t_list **stack_a)
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
			cost = tmp->cost;
		}
		lst = lst->next;
	}
}

void	cost(t_list **stack_a, t_list **stack_b)
{
	size_t	b_cost;
	size_t	a_cost;
	t_list	*lst;
	t_list	*node;

	lst = *stack_a;
	node = *stack_b;
	while (lst)
	{
		if (lst->index <= ft_lstsize(lst) / 2)
			a_cost = lst->index;
		else
			a_cost = ft_lstsize(lst) - (lst->index);
		if (lst->target->index <= ft_lstsize(node) / 2)
			b_cost = lst->target->index;
		else
			b_cost = ft_lstsize(node) - (lst->target->index);
		lst->cost = a_cost + b_cost;
		lst = lst->next;
	}
}
