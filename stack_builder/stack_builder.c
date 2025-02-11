/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:14 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/06 15:24:24 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*stack_a_builder(char **argv, int argc, int i, t_elem **lst)
{
	t_elem	*new_node;
	long	number;

	while (i < argc)
	{
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		new_node = ft_lstnew((int)number, 'a');
		if (!new_node)
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		ft_lstadd_back(lst, new_node);
		i++;
	}
	assign_index(*lst, 1);
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
	if (argc == 2)
		ft_free_split(final_argv, final_argc);
	return (lst);
}
