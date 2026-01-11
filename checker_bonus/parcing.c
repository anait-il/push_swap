/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 19:40:45 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 18:17:44 by anait-il         ###   ########.fr       */
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

void	not_digit(char **av, int ac, int i)
{
	int	j;

	j = 0;
	while (av[i][j])
	{
		if (av[i][j] == '+' || av[i][j] == '-')
		{
			if (!check_sign(av[i], j + 1))
				ft_error();
			j++;
		}
		if ((av[i][j] < '0' || av[i][j] > '9'
			|| av[i][j] == 9) && av[i][j] != ' ')
			ft_error();
		if ((av[i][j] >= '0' && av[i][j] <= '9')
			&& (av[i][j + 1] == '+' || av[i][j + 1] == '-'))
			ft_error();
		j++;
	}
}

int	_checking(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		not_digit(av, ac, i);
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
