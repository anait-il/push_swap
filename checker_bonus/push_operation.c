/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:08:25 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/12 13:46:47 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_list(t_list **dest, t_list **src)
{
	t_list	*lst;

	if (!src || !*src)
		return ;
	lst = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = lst;
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	push_list(stack_a, stack_b);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	push_list(stack_b, stack_a);
}
