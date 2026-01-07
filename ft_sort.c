/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelkabir <abdelkabir@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:20:38 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/07 02:10:13 by abdelkabir       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list *smollest_targ(t_list *lst, t_list *node)
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

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	size_t	smoll_cost;
	size_t	size;
	t_list	*lst;
	size_t	i;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 3)
	{
		lst = *stack_a;
		ft_index(stack_a);
		ft_index(stack_b);
		target_of_node(stack_a, stack_b);
		cost(stack_a, stack_b);
		smoll_cost = smollest_cost(stack_a);
		while ((*stack_a)->cost != smoll_cost)
		{
			if ((ft_lstsize(*stack_a) / 2) >=  lst->index)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
		while ((*stack_b)->index != (*stack_a)->target->index)
		{
			if ((ft_lstsize(*stack_b) / 2) >=  (*stack_a)->target->index)
				ft_rb(stack_b);
			else
				ft_rrb(stack_b);
		}
		ft_pb(stack_a, stack_b);
	}
	ft_sort_3num(stack_a);
	while (ft_lstsize(*stack_b))
	{
		ft_pa(stack_a, stack_b);
	}
	ft_index(stack_a);
	while ((*stack_a)->index != _find_smollest_num(*stack_a))
		ft_ra(stack_a);
}
