# compiler
CC = cc

# compilation flags
CFLAGS = -Wall -Werror -Wextra -g -I.

# source code
SRCS = 	main.c \
		stack_builder/input_utils.c \
		stack_builder/input_validator.c \
		stack_builder/stack_builder.c \
		stack_builder/index_definer_algo.c \
		utils/linked_lst_utils.c \
		utils/ft_split.c \
		utils/ft_atol.c \
		movements/movements.c \
		movements/movements_aggregated.c \
		algorithm/prep_stack_a.c \
		algorithm/prep_stack_b.c \
		algorithm/algo_utils.c \
		algorithm/algorithm.c \
		algorithm/perform_movements.c \
		algorithm/handle_nodes.c \
		algorithm/algo_case_1.c \
		algorithm/algo_case_2.c \
		algorithm/algo_case_3.c

# objects
OBJECTS = $(SRCS:.c=.o)

# program name
NAME = push_swap

# rules
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

leakfull1:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} "5 3 2 1"

leakfull2:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} "5 3 e 1"

clean:
	@rm -rf $(OBJECTS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Program cleaned."

re: fclean all
	@echo "Object files recreated."
	@echo "Program recreated."

.PHONY: all clean fclean re leakfull