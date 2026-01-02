/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:21:16 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/02 19:35:34 by anait-il         ###   ########.fr       */
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

int	check_sign(char *av, int i)
{
	if (av[i] < '0' || av[i] > '9')
		return (0);
	return (1);
}

void	check_space(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		else
			return ;
	}
	ft_error();
}

int	_checking(char **av, int ac)	
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (!check_sign(av[i], j + 1))
					return (0);
				j++;
			}
			if ((av[i][j] < '0' || av[i][j] > '9' || av[i][j] == 9) && av[i][j] != ' ')
				return (0);
			if (av[i][j] >= '0' && av[i][j] <= '9' && (av[i][j+1] == '+' || av[i][j + 1] == '-'))
				ft_error();
			j++;
		}
		check_space(av[i]); 
		i++;
	}
	return (1);
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
