NAME = push_swap.a

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c  ft_error.c  ft_split.c  linkd_lst.c  parcing.c  push_swap.c  push_operation.c  revers_rotat_operation.c  rotat_operation.c  swap_operation.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c push_swap.h
	$(CC)  -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
