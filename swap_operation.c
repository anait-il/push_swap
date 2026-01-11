/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:09:43 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 16:07:15 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_list(t_list **head)
{
	t_list	*lst;

	if (!head || !*head)
		return ;
	if (ft_lstsize(*head) == 1)
		return ;
	lst = *head;
	*head = lst->next;
	lst->next = (*head)->next;
	(*head)->next = lst;
}

void	ft_sa(t_list **stack_a)
{
	ft_swap_list(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	ft_swap_list(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap_list(stack_a);
	ft_swap_list(stack_b);
	write(1, "ss\n", 3);
}
