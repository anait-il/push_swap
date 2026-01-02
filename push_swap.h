#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct			s_list
{
	int					content;
	struct s_list		*next;
}						t_list;

size_t	ft_strlcpy(char *dst, const char *src, size_t len);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
long	ft_atoi(const char *str);
void	ft_error(void);


#endif