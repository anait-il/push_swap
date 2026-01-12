/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parcing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:43:34 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/12 21:47:14 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parcing_new_line(char *file, t_list **stack_a)
{
	int	i;

	i = 0;
	if (file[i] == '\n')
	{
		write(2, "Error\n", 6);
		free_list_exit(stack_a);
	}
}

void	check_reverse_rotate(char *tmp, t_list **stack_a)
{
	if (!ft_strncmp(tmp, "ra\n"))
		return ;
	else if (!ft_strncmp(tmp, "rb\n"))
		return ;
	else if (!ft_strncmp(tmp, "rr\n"))
		return ;
	else if (!ft_strncmp(tmp, "rra\n"))
		return ;
	else if (!ft_strncmp(tmp, "rrb\n"))
		return ;
	else if (!ft_strncmp(tmp, "rrr\n"))
		return ;
	else
	{
		write(2, "Error\n", 6);
		free_list_exit(stack_a);
	}
}

void	check_wrong_instruction(char *tmp, t_list **stack_a)
{
	if (!ft_strncmp(tmp, "sa\n"))
		return ;
	else if (!ft_strncmp(tmp, "sb\n"))
		return ;
	else if (!ft_strncmp(tmp, "ss\n"))
		return ;
	else if (!ft_strncmp(tmp, "pa\n"))
		return ;
	else if (!ft_strncmp(tmp, "pb\n"))
		return ;
	else
		check_reverse_rotate(tmp, stack_a);
}
