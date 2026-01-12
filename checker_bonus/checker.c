/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:21:38 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/12 19:46:08 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

static void	create_node(t_list **stack_a, char **p)
{
	int		content;
	size_t	j;
	t_list	*node;

	j = 0;
	while (p[j])
	{
		content = ft_atoi(p[j]);
		if (check_duplicate(*stack_a, content))
			ft_error();
		node = ft_lstnew(content);
		if (!node)
		{
			free_split(p);
			free_list_exit(stack_a);
		}
		ft_lstadd_back(stack_a, node);
		j++;
	}
}

void	fil_stack(t_list **stack_a, char **av, int ac)
{
	int		i;
	long	j;
	char	**p;
	t_list	*node;
	int		content;

	i = 1;
	while (i < ac)
	{
		p = ft_split(av[i], ' ');
		if (!p)
			ft_error();
		create_node(stack_a, p);
		free_split(p);
		i++;
	}
}

void	checker_program(t_list **stack_a, t_list **stack_b, char *file)
{
	int		i;
	char	**p;

	i = 0;
	p = ft_split(file, '\n');
	while (p[i])
	{
		if (!ft_strncmp(p[i], "sa"))
			ft_sa(stack_a);
		else if (!ft_strncmp(p[i], "sb"))
			ft_sb(stack_b);
		else if (!ft_strncmp(p[i], "ss"))
			ft_ss(stack_a, stack_b);
		else if (!ft_strncmp(p[i], "pa"))
			ft_pa(stack_a, stack_b);
		else if (!ft_strncmp(p[i], "pb"))
			ft_pb(stack_a, stack_b);
		else if (!ft_strncmp(p[i], "ra"))
			ft_ra(stack_a);
		else if (!ft_strncmp(p[i], "rb"))
			ft_rb(stack_b);
		else if (!ft_strncmp(p[i], "rr"))
			ft_rr(stack_a, stack_b);
		else if (!ft_strncmp(p[i], "rra"))
			ft_rra(stack_a);
		else if (!ft_strncmp(p[i], "rrb"))
			ft_rrb(stack_b);
		else if (!ft_strncmp(p[i], "rrr"))
			ft_rrr(stack_a, stack_b);
		else
		{
			free_split(p);
			free_list(stack_a);
			free_list(stack_b);
			ft_error();
		}
		i++;
	}
	free_split(p);
}

void	ko_or_ok(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) != 0)
	{
		write(1, "KO", 2);
		free_list(stack_a);
	}
	else
	{
		if (is_sorted(*stack_a))
		{
			write(1, "KO", 2);
			free_list(stack_a);
			exit(0);
		}
		else
		{
			write(1, "OK", 2);
			free_list(stack_a);
			exit(0);
		}
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*file;
	char	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	file = NULL;
	if (ac == 1)
		return (0);
	if (!_checking(av, ac))
		return (write(2, "Error\n", 6));
	fil_stack(&stack_a, av, ac);
	tmp = get_next_line(0);
	while (tmp)
	{
		parcing_new_line(tmp, &stack_a);
		check_wrong_instruction(tmp, &stack_a);
		file = ft_strjoin(file, tmp);
		free(tmp);
		tmp = get_next_line(0);
	}
	if (file)
		checker_program(&stack_a, &stack_b, file);
	ko_or_ok(&stack_a, &stack_b);
}
