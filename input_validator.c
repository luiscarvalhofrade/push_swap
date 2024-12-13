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

char	**input_argv_validator(int argc, char **argv)
{
	char	**final_argv;

	if (argc == 2)
		final_argv = ft_split(argv[1], ' ');
	else
		final_argv = argv;
	return (final_argv);
}

// t_list	*input_type_validator(int i, char **argv, int argc)
// {
// 	int	k;

// 	k = 0;
// 	while (i < argc)
// 	{
// 		k = 0;
// 		while (argv[i][k] != '\0')
// 		{
// 			if (ft_isdigit(argv[i][k]) != 1 || argv[i][k] == '-')
// 				return (0);
// 			k++;
// 		}
// 		new_node = ft_lstnew((atoi(argv[i])), 'a');
// 		if (!new_node)
// 			return (0);
// 		ft_lstadd_back(&lst, new_node);
// 		i++;
// 	}
// }