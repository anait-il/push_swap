/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelkabir <abdelkabir@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:21:16 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/03 12:45:10 by abdelkabir       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		j = 0;
		p = ft_split(av[i], ' ');
		while (p[j])
		{
			content = ft_atoi(p[j]);
			if (check_duplicate(*stack_a, content))
				ft_error();
			node = ft_lstnew(content);
			ft_lstadd_back(stack_a, node);
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	t_list	*stack_a = NULL;
	 t_list	*stack_b = NULL;

	if (ac == 1)
		return 0;
	if (!_checking(av, ac))
		return (write(2, "Error\n", 6));
	fil_stack(&stack_a, av, ac);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}

