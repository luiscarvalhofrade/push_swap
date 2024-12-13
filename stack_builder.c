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
	t_list	*lst;
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
	if (!input_item_validator(final_argv, final_argc, i, &lst))
		return (NULL);
	return (lst);
}
