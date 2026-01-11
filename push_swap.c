/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:21:16 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 13:23:42 by anait-il         ###   ########.fr       */
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

void	create_node(t_list **stack_a, char **p)
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
	int content;

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

void f()
{
	system ("leaks push_swap");
}

int	main(int ac, char **av)
{
	atexit(f);
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
	if (ft_lstsize(stack_a) == 1)
		return (free_list(&stack_a), 0);
	else if (ft_lstsize(stack_a) == 2)
		ft_sort_2(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		ft_sort_3num(&stack_a);
	else if (ft_lstsize(stack_a) == 5 || ft_lstsize(stack_a) == 4)
		ft_sort_four_and_five(&stack_a, &stack_b);
	else
		ft_sort(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
