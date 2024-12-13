/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:14 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/05 19:44:16 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_builder(int argc, char **argv)
{
	t_list	*new_node;
	t_list	*lst;
	char	**final_argv;
	int		i;
	int		k;

	lst = NULL;
	i = 1;
	final_argv = input_argv_validator(argc, argv);
	if (argc == 2)
	{
		argc = ft_count_words(argv[1], ' ');
		i = 0;
	}
	while (i < argc)
	{
		k = 0;
		while (final_argv[i][k] != '\0')
		{
			if (ft_isdigit(final_argv[i][k]) != 1 || final_argv[i][k] == '-')
				return (0);
			k++;
		}
		new_node = ft_lstnew((atoi(final_argv[i])), 'a');
		if (!new_node)
			return (0);
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}

// t_list	*stack_builder(int argc, char **argv)
// {
// 	t_list	*new_node;
// 	t_list	*lst;
// 	char	**final_argv;
// 	int		final_argc;
// 	int		i;

// 	lst = NULL;
// 	final_argv = input_argv_validator(argc, argv);
// 	final_argc = input_argv_validator(argc);
// 	while (i < final_argc)
// 	{
// 		new_node = input_type_validator(i, final_argv, final_argc);
// 		new_node = ft_lstnew((atoi(argv[i])), 'a');
// 		if (!new_node)
// 			return (0);
// 		ft_lstadd_back(&lst, new_node);
// 		i++;
// 	}


// }
