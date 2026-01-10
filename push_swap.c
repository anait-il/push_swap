/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:21:16 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/10 16:14:32 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *head)
{
	if (!head)
		return 1;
	while (head->next)
	{
		if (head->content > head->next->content)
			return 0;
		head = head->next;
	}
	return 1;
}

void	ft_index(t_list **stack_a)
{
	t_list	*lst;
	int		i;

	lst = *stack_a;
	i = 0;
	while (lst)
	{
		lst->index = i;
		i++;
		lst = lst->next;
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
		j = 0;
		p = ft_split(av[i], ' ');
		if (!p)
			ft_error();
		while (p[j])
		{
			content = ft_atoi(p[j]);
			if (check_duplicate(*stack_a, content))
				ft_error();
			node = ft_lstnew(content);
			if (!node)
				free_list(stack_a);
			ft_lstadd_back(stack_a, node);
			j++;
		}
		free_split(p, j);
		i++;
	}
}

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return 0;
	if (!_checking(av, ac))
		return (write(2, "Error\n", 6));
	fil_stack(&stack_a, av, ac);
	if (is_sorted(stack_a))
		return (free_list(&stack_a), 0);
	ft_index(&stack_a);
	if (ac == 2)
		return (0);
	else if (ac == 3)
		ft_sort_2(&stack_a);
	else if (ac == 4)
		ft_sort_3num(&stack_a);
	else if (ac == 6 || ac == 5)
		ft_sort_four_and_five(&stack_a, &stack_b);
	else
		ft_sort(&stack_a, &stack_b);
	t_list *node = stack_a;
	while (stack_a)
	{
		node = stack_a->next;
		free(stack_a);
		stack_a = node;
	}
	// free(stack_a);
	return (0);
}
