/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:32:06 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 15:55:09 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

void	free_list(t_list **stack_a)
{
	t_list	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	while (*stack_a)
	{
		node = (*stack_a)->next;
		free(*stack_a);
		*stack_a = node;
	}
}

void	free_list_exit(t_list **stack_a)
{
	t_list	*node;

	if (!*stack_a)
		return ;
	node = *stack_a;
	while (*stack_a)
	{
		node = (*stack_a)->next;
		free(*stack_a);
		*stack_a = node;
	}
	exit(1);
}
