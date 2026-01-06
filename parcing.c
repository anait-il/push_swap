/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:40:45 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/05 22:24:02 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_duplicate(t_list *last, int content)
{
	while (last)
	{
		if (last->content == content)
			return (1);
		last = last->next;
	}
	return (0);
}

