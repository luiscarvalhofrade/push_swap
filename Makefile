# compiler
CC = cc

# compilation flags
CFLAGS = -Wall -Werror -Wextra -g -I.

# source code
SRCS = 	main.c \
		input_utils.c \
		input_validator.c \
		linked_lst_utils.c \
		stack_builder.c \
		movements.c \
		movements_aggregated.c \
		index_definer_algo.c \
		utils/ft_split.c \
		utils/ft_atoi.c \
		update_pos_n_target_pos.c \
		calculate_mov_costs.c \
		algo_case_1.c \
		algo_case_2.c \
		algo_case_3.c \
		algo.c \

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

leakfull:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} "5 8 6 10 -8 -6 -10"

clean:
	@rm -rf $(OBJECTS)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Program cleaned."

re: fclean all
	@echo "Object files recreated."
	@echo "Program recreated."

.PHONY: all clean fclean re