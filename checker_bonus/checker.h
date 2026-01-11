/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:53:08 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 18:25:09 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	size_t				cost;
	struct s_list		*target;
	size_t				index;
	int					content;
	struct s_list		*next;
}						t_list;

int		check_sign(char *av, int i);
void	check_space(char *av);
void	not_digit(char **av, int ac, int i);
int		_checking(char **av, int ac);
void	ft_error(void);
void	fil_stack(t_list **stack_a, char **av, int ac);
char	**ft_split(char const *s, char c);


#endif