#include "push_swap.h"

int	duplicates_validator(t_list **lst)
{
	int		current_number;
	t_list	*current_node;
	t_list	*iteration_node;

	if (!lst || !*lst)
		return (0);
	current_node = *lst;
	while (current_node)
	{
		current_number = (current_node)->number;
		iteration_node = (current_node)->next_number;
		while (iteration_node->next_number != NULL)
		{
			if (current_number == iteration_node->number)
				return (0);
			iteration_node = iteration_node->next_number;
		}
		current_node = current_node->next_number;
	}
	return (1);
}

char	**argv_validator(int argc, char **argv)
{
	char	**final_argv;

	if (argc == 1)
		final_argv = ft_split(argv[1], ' ');
	else
		final_argv = argv;
	return (final_argv);
}