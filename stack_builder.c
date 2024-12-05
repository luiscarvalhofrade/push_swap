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

#include "stack_builder.h"

int	*convert_argv(char *ints)
{

}

t_list	stack_builder(char *argv)
{
	int		*ints_for_initial_stack;
	t_list	*lst;
	t_list	*new_node;
	t_list	*last_node;

	ints_for_initial_stack = convert_argv(argv);
	last_node = found_last_node(lst);
	new_node = malloc(sizeof(t_list));
	while (*ints_for_initial_stack)
	{
		if (!lst)
			return (0);
		while (lst)
		{
			if(!lst)
			{
				lst = new_node;
			}
			new_node->number = ints_for_initial_stack++;
			new_node->next_number = NULL;
			lst = lst->next_number;
		}
	}

}
