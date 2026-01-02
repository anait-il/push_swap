/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:21:16 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/02 19:43:29 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fil_stack(char **av, int ac)
{
	int		i;
	long	j;
	char	**p;
	t_list	*head;
	t_list	*node;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		j = 0;
		p = ft_split(av[i], ' ');
		while (p[j])
		{
			node = ft_lstnew(ft_atoi(p[j]));
			ft_lstadd_back(&head, node);
			j++;
		}
		i++;
	}
	return (head);
}

int main(int ac, char **av)
{
	int		i;
	int		j;
	char	**p;
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	i = 0;
	j = 0;
	if (ac == 1)
		return 0;
	if (!_checking(av, ac))
		return (write(2, "Error\n", 6));
	stack_a = fil_stack(av, ac);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}
