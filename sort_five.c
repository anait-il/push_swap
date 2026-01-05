/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:09:05 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/05 18:09:09 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	_find_smollest_num(t_list *stack_a)
{
	t_list	*lst;
	t_list	*tmp;
	size_t	rank;

	lst = stack_a;
	tmp = stack_a;
	rank = lst->index;
	while (lst)
	{
		if (lst->content < tmp->content)
		{
			tmp = lst;
			lst = lst->next;
			rank = tmp->index;
		}
		else
			lst = lst->next;
	}
	return (rank);	
}

void	ft_sort_5num(t_list **stack_a, t_list **stack_b)
{
	size_t	rank;
	size_t	size;

	size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) != 3)
	{
		ft_index(stack_a);
		rank = _find_smollest_num(*stack_a);
		if (rank > (size / 2))
		{
			while ((*stack_a)->index != rank)
				ft_rra(stack_a);
		}	
		else
		{
			while ((*stack_a)->index != rank)
				ft_ra(stack_a);
		}
		ft_pb(stack_b, stack_a);
	}
	ft_sort_3num(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
