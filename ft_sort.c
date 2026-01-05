/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:20:38 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/05 20:36:15 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	size_t	rank;
	size_t	size;

	while (ft_lstsize(*stack_a) != 3)
	{
		size = ft_lstsize(*stack_a);
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
		ft_pb(stack_a, stack_b);
	}
	ft_sort_3num(stack_a);
	while (ft_lstsize(*stack_b) != 0)
		ft_pa(stack_a, stack_b);
}
