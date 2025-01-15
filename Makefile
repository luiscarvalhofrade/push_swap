# compiler
CC = cc

# compilation flags
CFLAGS = -Wall -Werror -Wextra -I.

# source code
SRCS = 	main.c \
		input_validator.c \
		stack_builder.c \
		stack_builder_utils.c \
		movements.c \
		movements_utils.c \
		resolution_algorithm.c \
		resolution_algorithm_utils.c \
		utils/ft_split.c \
		utils/ft_atoi.c

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