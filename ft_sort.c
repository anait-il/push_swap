/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:20:38 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/09 12:14:53 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*large_targe(t_list *stack_a, t_list *stack_b)
{
	int		ftarget;
	t_list	*target;

	target = NULL;
	while (stack_b)
	{
		if (stack_b->content > stack_a->content && target == NULL)
		{
			ftarget = stack_b->content;
			target = stack_b;
		}
		else if (stack_b->content > stack_a->content)
		{
			if (stack_b->content > ftarget)
			{
				ftarget = stack_b->content;
				target = stack_b;
			}
		}
		stack_b = stack_b->next;
	}
	return (target);
}

t_list	*biggest_num(t_list *stack_a)
{
	t_list	*lst;
	t_list	*tmp;

	lst = stack_a;
	tmp = stack_a;
	while (lst)
	{
		if (lst->content > tmp->content)
			tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_list	*smollest_targ(t_list *lst, t_list *node)
{
	int		ftarget;
	t_list	*target;

	target = NULL;
	while (node)
	{
		if (node->content < lst->content && target == NULL)
		{
			ftarget = node->content;
			target = node;
		}
		else if (node->content < lst->content)
		{
			if (node->content > ftarget)
			{
				ftarget = node->content;
				target = node;
			}
		}
		node = node->next;
	}
	return (target);
}

void	target_of_node(t_list **stack_a, t_list **stack_b)
{
	t_list	*target;
	t_list	*lst;

	lst = *stack_a;
	target = NULL;
	while (lst)
	{
		target = smollest_targ(lst, *stack_b);
		if (target == NULL)
			lst->target = biggest_num(*stack_b);
		else
			lst->target = target;
		lst = lst->next;
	}
}

void	push_foreward(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;

	lst = smollest_cost(stack_a);
	optimization(stack_a, stack_b, lst);
	while ((*stack_a)->cost != lst->cost)
	{
		if ((ft_lstsize(*stack_a) / 2) >=  lst->index)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	while ((*stack_b) != (*stack_a)->target)
	{
		if ((ft_lstsize(*stack_b) / 2) >= (*stack_a)->target->index)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
	ft_pb(stack_a, stack_b);
}

void	optimization(t_list **stack_a, t_list **stack_b, t_list *best_cost)
{
	if ((ft_lstsize(*stack_a) - best_cost->index ) == (ft_lstsize(*stack_b) - best_cost->target->index))
	{
		while ((*stack_a)->cost != best_cost->cost)
		{
			if ((ft_lstsize(*stack_a) / 2) >=  best_cost->index)
				ft_rr(stack_a, stack_b);
			else
				ft_rrr(stack_a, stack_b);
		}
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	if ((*stack_b)->content > (*stack_b)->next->content)
		ft_sb(stack_b);
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
