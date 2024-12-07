/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:27:03 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/06 13:27:04 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_ascending_checker(t_list **lst)
{
	t_list	*current;
	t_list	*next_node;

	current = *lst;
	while (current->next_number != NULL)
	{
		next_node = current->next_number;
		if (current->number > next_node->number)
		{
			printf("\ncurr:%d > next:%d\n", current->number, next_node->number);
			return (0);
		}
		current = current->next_number;
	}
	return (1);
}
