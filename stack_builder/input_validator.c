/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:04:14 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/06 11:12:57 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_duplicates_validator(t_elem **lst)
{
	int		current_number;
	t_elem	*current_node;
	t_elem	*iteration_node;

	if (!lst || !*lst)
		return (0);
	current_node = *lst;
	while (current_node)
	{
		current_number = (current_node)->number;
		iteration_node = (current_node)->next_number;
		while (iteration_node)
		{
			if (current_number == iteration_node->number)
				return (0);
			iteration_node = iteration_node->next_number;
		}
		current_node = current_node->next_number;
	}
	return (1);
}

int	ft_nbr(char *nbr)
{
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	while (*nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (0);
		nbr++;
	}
	return (1);
}

int	input_item_validator(char **argv, int argc, int i)
{
	while (i < argc)
	{
		if (ft_nbr(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	input_validator(int argc, char **argv)
{
	char	**final_argv;
	int		final_argc;
	int		i;

	i = 0;
	final_argv = input_argv_validator(argc, argv);
	if (!final_argv)
		return (0);
	final_argc = input_argc_validator(argc, argv);
	if (argc == 2)
	{
		i = 0;
		ft_free_split(final_argv, final_argc);
	}
	else if (argc >= 3)
		i = 1;
	if (input_item_validator(final_argv, final_argc, i) == 0)
	{
		ft_free_split(final_argv, final_argc);
		return (0);
	}
	return (1);
}
