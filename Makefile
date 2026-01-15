NAME = push_swap

BONUS_NAME = checker

CC = cc

BONUS_DIR = checker_bonus

FLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c  ft_error.c  ft_split.c  linkd_lst.c  parcing.c  push_swap.c  push_operation.c  revers_rotat_operation.c  rotat_operation.c  swap_operation.c  sort_tree.c  sort_five.c  ft_sort.c  cost.c  target.c ft_free.c utils.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = $(BONUS_DIR)/checker.c  $(BONUS_DIR)/ft_error.c  $(BONUS_DIR)/ft_split.c  $(BONUS_DIR)/get_next_line_utils.c  $(BONUS_DIR)/parcing.c  $(BONUS_DIR)/ft_atoi.c  $(BONUS_DIR)/ft_free.c  $(BONUS_DIR)/get_next_line.c  $(BONUS_DIR)/linkd_lst.c  $(BONUS_DIR)/push_operation.c  $(BONUS_DIR)/rotat_operation.c  $(BONUS_DIR)/revers_rotat_operation.c  $(BONUS_DIR)/swap_operation.c  $(BONUS_DIR)/ft_strcmp.c  $(BONUS_DIR)/checker_parcing.c  $(BONUS_DIR)/checker_program.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h $(BONUS_DIR)/checker.h
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all
