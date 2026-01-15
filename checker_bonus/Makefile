NAME = checker.a

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC = checker.c  ft_error.c  ft_split.c  get_next_line_utils.c  parcing.c  ft_atoi.c  ft_free.c  get_next_line.c  linkd_lst.c  push_operation.c  rotat_operation.c  revers_rotat_operation.c  swap_operation.c  ft_strcmp.c  checker_parcing.c  checker_program.c
OBJ = $(SRC:.c=.o)

bonus : all

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	cc $(NAME) -o checker

%.o : %.c checker.h get_next_line.h
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
