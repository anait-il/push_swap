/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:20:38 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/06 22:35:46 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*biggest_num(t_list *stack_a)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *stack_a;
	tmp = *stack_a;
	while (lst)
	{
		if (lst->content < tmp->content)
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
			lst->target = biggest_num(*stack_a);
		else
			lst->target = target;
		lst = lst->next;
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	size_t	smoll_cost;
	size_t	size;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 3)
	{
		ft_index(stack_a);
		ft_index(stack_b);
		target_of_node(stack_a, stack_b);
		cost(stack_a, stack_b);
		smoll_cost = smollest_cost(stack_a);
	}
}
