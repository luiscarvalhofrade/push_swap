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
		utils/ft_atoi.c \
		movements/movements.c \
		movements/movements_aggregated.c \
		final_algorithm/prep_stack_a.c \
		final_algorithm/prep_stack_b.c \
		final_algorithm/algo_final_utils.c \
		final_algorithm/algo_final.c \
		final_algorithm/perform_movements.c \
		final_algorithm/handle_nodes.c \
		final_algorithm/algo_case_1.c \
		final_algorithm/algo_case_2.c \
		# proprietary_algorithm/algo_case_1.c \
		# proprietary_algorithm/algo_case_2.c \
		# proprietary_algorithm/algo_case_3.c \
		# proprietary_algorithm/algo_proprietary.c \
		# proprietary_algorithm/algo_proprietary_utils.c \
		# proprietary_algorithm/handle_nodes.c \
		# algorithms/mia/update_pos_n_target_pos.c \
		# algorithms/mia/calculate_mov_costs.c \
		# algorithms/mia/algo_case_1.c \
		# algorithms/mia/algo_case_2.c \
		# algorithms/mia/algo_case_3.c \
		# algorithms/mia/algo_mia.c \
		# algorithms/radix/algo_radix.c \
		# algorithms/radix/algo_radix_utils.c \

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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} 5 8 6 3 -8 -6 -10

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