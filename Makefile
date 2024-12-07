# compiler
CC = cc

# compilation flags
CFLAGS = -Wall -Werror -Wextra -I.

# source code
SRCS = main.c stack_builder.c stack_builder_utils.c movements.c movements_utils.c \
	resolution_algorithm.c resolution_algorithm_utils.c

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
	@echo "program cleaned."

re: fclean all

.PHONY: all clean fclean re