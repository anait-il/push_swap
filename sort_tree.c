/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:09:13 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/05 20:37:30 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3num(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content && (*stack_a)->content > (*stack_a)->next->next->content)
		ft_ra(stack_a);
	if ((*stack_a)->content >(*stack_a)->next->content)
		ft_sa((stack_a));
	if ((*stack_a)->content >(*stack_a)->next->next->content)
		ft_rra((stack_a));
	if ((*stack_a)->next->content >(*stack_a)->next->next->content)
	{
		ft_rra((stack_a));
		ft_sa((stack_a));
	}
}
