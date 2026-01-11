/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:28:06 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 16:06:57 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*small(t_list *stack_a)
{
	t_list	*lst;
	t_list	*tmp;

	lst = stack_a;
	tmp = stack_a;
	while (lst)
	{
		if (lst->content < tmp->content)
			tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

t_list	*big_targ(t_list *stack_b, t_list *stack_a)
{
	int		ftarget;
	t_list	*target;

	target = NULL;
	while (stack_a)
	{
		if (stack_a->content > stack_b->content && target == NULL)
		{
			ftarget = stack_a->content;
			target = stack_a;
		}
		else if (stack_a->content > stack_b->content)
		{
			if (stack_a->content < ftarget)
			{
				ftarget = stack_a->content;
				target = stack_a;
			}
		}
		stack_a = stack_a->next;
	}
	return (target);
}

void	reverse_targ(t_list **stack_a, t_list **stack_b)
{
	t_list	*target;
	t_list	*b_list;

	b_list = *stack_b;
	target = NULL;
	while (b_list)
	{
		target = big_targ(b_list, *stack_a);
		if (target == NULL)
			b_list->target = small(*stack_a);
		else
			b_list->target = target;
		b_list = b_list->next;
	}
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	size_t	smoll_cost;
	size_t	size;
	t_list	*lst;
	size_t	i;

	while (ft_lstsize(*stack_b) != 0)
	{
		ft_index(stack_a);
		ft_index(stack_b);
		reverse_targ(stack_a, stack_b);
		while (*stack_a != (*stack_b)->target)
		{
			if ((ft_lstsize(*stack_a) / 2) >= (*stack_b)->target->index)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
		ft_pa(stack_a, stack_b);
	}
}
