/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:08:38 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/11 13:24:07 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct			s_list
{
	size_t				cost;
	struct s_list		*target;
	size_t				index;
	int					content;
	struct s_list		*next;
}						t_list;

//libft
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int	ft_atoi(const char *str);
//parcing
void	ft_error(void);
int	_checking(char **av, int ac);
void	check_space(char *av);
int	check_sign(char *av, int i);
int	check_duplicate(t_list *last, int content);
int	is_sorted(t_list *head);
//operations
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
//sort
void	ft_sort_2(t_list **stack_a);
void	ft_index(t_list **stack_a);
void	ft_sort_3num(t_list **stack_a);
void	ft_sort_four_and_five(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a, t_list **stack_b);
t_list	*_find_smollest_num(t_list *stack_a);
void	ft_sort_100(t_list **stack_a, t_list **stack_b);
//turk
void	cost(t_list **stack_a, t_list **stack_b);
t_list	*smollest_cost(t_list **stack_a);
t_list	*smollest_targ(t_list *lst, t_list *node);
t_list	*biggest_num(t_list *stack_a);
void	target_of_node(t_list **stack_a, t_list **stack_b);
void	reverse_targ(t_list **stack_a, t_list **stack_b);
int	cost_by_rotat(t_list **stack_a, t_list **stack_b, t_list *lst);
t_list	*big_targ(t_list *lst, t_list *node);
t_list	*small(t_list *stack_a);
void	push_back(t_list **stack_a, t_list **stack_b);
void	push_foreward(t_list **stack_a, t_list **stack_b);
void	optimization(t_list **stack_a, t_list **stack_b, t_list *best_cost);
//free
void	free_list(t_list **stack_a);
void	free_split(char **p);
void	free_list_exit(t_list **stack_a);

#endif
