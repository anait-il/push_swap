/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotat_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:08:59 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/12 13:44:49 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_list(t_list **head)
{
	t_list	*lst;
	t_list	*last_node;

	lst = *head;
	if (!head || !*head)
		return ;
	if (ft_lstsize(*head) == 1)
		return ;
	*head = lst->next;
	last_node = ft_lstlast(lst);
	last_node->next = lst;
	lst->next = NULL;
}

void	ft_ra(t_list **stack_a)
{
	rotate_list(stack_a);
}

void	ft_rb(t_list **stack_b)
{
	rotate_list(stack_b);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_list(stack_a);
	rotate_list(stack_b);
}
