/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:21:38 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 18:47:03 by anait-il         ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*file;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	if (!_checking(av, ac))
		return (write(2, "Error\n", 6));
	fil_stack(&stack_a, av, ac);
	while (file = get_next_line(0))
	{
		file = ft_strjoin()
	}
}
