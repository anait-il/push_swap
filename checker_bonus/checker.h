/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:53:08 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/13 10:13:50 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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
int		ft_atoi(const char *str);
int		ft_strncmp(char const *s1, const char *s2);
int		check_duplicate(t_list *last, int content);
int		is_sorted(t_list *head);
void	exit_with_ok(void);

void	parcing_new_line(char *file, t_list **stack_a);
void	check_reverse_rotate(char *tmp, t_list **stack_a);
void	check_wrong_instruction(char *tmp, t_list **stack_a);

int		check_instructions(char *s, t_list **stack_a, t_list **stack_b);
void	checker_program(t_list **stack_a, t_list **stack_b, char **file);
void	ko_or_ok(t_list **stack_a, t_list **stack_b);

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_lstsize(t_list *lst);

void	free_split(char **p);
void	free_list_exit(t_list **stack_a);
void	free_list(t_list **stack_a);

void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

#endif