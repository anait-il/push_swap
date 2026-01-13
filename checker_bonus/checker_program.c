/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:46:12 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/13 10:03:11 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_instructions(char *s, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(s, "sa"))
		ft_sa(stack_a);
	else if (!ft_strncmp(s, "sb"))
		ft_sb(stack_b);
	else if (!ft_strncmp(s, "ss"))
		ft_ss(stack_a, stack_b);
	else if (!ft_strncmp(s, "pa"))
		ft_pa(stack_a, stack_b);
	else if (!ft_strncmp(s, "pb"))
		ft_pb(stack_a, stack_b);
	else if (!ft_strncmp(s, "ra"))
		ft_ra(stack_a);
	else if (!ft_strncmp(s, "rb"))
		ft_rb(stack_b);
	else if (!ft_strncmp(s, "rr"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strncmp(s, "rra"))
		ft_rra(stack_a);
	else if (!ft_strncmp(s, "rrb"))
		ft_rrb(stack_b);
	else if (!ft_strncmp(s, "rrr"))
		ft_rrr(stack_a, stack_b);
	else
		return (1);
	return (0);
}

void	checker_program(t_list **stack_a, t_list **stack_b, char **file)
{
	int		i;
	char	**p;

	i = 0;
	p = ft_split(*file, '\n');
	free(*file);
	*file = NULL;
	if (!p)
		return ;
	while (p[i])
	{
		if (!check_instructions(p[i], stack_a, stack_b))
			i++;
		else
		{
			free_split(p);
			free_list(stack_a);
			free_list(stack_b);
			ft_error();
		}
	}
	free_split(p);
}

void	ko_or_ok(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) != 0)
	{
		write(1, "KO\n", 3);
		free_list(stack_a);
		free_list(stack_b);
	}
	else
	{
		if (is_sorted(*stack_a))
		{
			write(1, "KO\n", 3);
			free_list(stack_a);
			exit(0);
		}
		else
		{
			write(1, "OK\n", 3);
			free_list(stack_a);
			exit(0);
		}
	}
}
