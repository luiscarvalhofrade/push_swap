/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:14 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/15 19:10:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*fill_index(t_elem **lst, int argc)
{
	int		**matrix;
	int		i;
	int		j;
	int		k;
	int		min_val;
	t_elem	*current;

	matrix = (int **)malloc(2 * sizeof(int *));
	matrix[0] = (int *)malloc(argc * sizeof(int));
	matrix[1] = (int *)malloc(argc * sizeof(int));
	current = *lst;
	i = 0;
	while (current)
	{
		matrix[0][i] = current->number;
		i++;
		current = current->next_number;
	}
	i = 1;
	j = 0;
	k = 1;
	while (k <= argc)
	{
		min_val = matrix[0][0];
		while (i < argc)
		{
			if (min_val > matrix[0][i] && matrix[1][j] != k)
				j = i;
			i++;	
		}
		matrix[1][j] = k;
		k++;
	}
}

t_elem	*stack_a_builder(char **argv, int argc, int i, t_elem **lst)
{
	t_elem	*new_node;

	while (i < argc)
	{
		new_node = ft_lstnew((ft_atoi(argv[i])), 'a');
		if (!new_node)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		ft_lstadd_back(lst, new_node);
		i++;
	}
	//lst = fill_index(lst);
	return (*lst);
}

t_elem	*stack_builder(int argc, char **argv)
{
	t_elem	*lst;
	char	**final_argv;
	int		final_argc;
	int		i;

	lst = NULL;
	final_argv = input_argv_validator(argc, argv);
	if (!final_argv)
		return (NULL);
	final_argc = input_argc_validator(argc, argv);
	if (argc == 2)
		i = 0;
	else if (argc >= 3)
		i = 1;
	else
		return (NULL);
	stack_a_builder(final_argv, final_argc, i, &lst);
	return (lst);
}
