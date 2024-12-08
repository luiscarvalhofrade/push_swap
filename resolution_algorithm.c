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
			return (0);
		current = current->next_number;
	}
	return (1);
}

int	resolution_algorithm(t_list **lst1, t_list **lst2)
{
	int	result;

	result = stack_ascending_checker(lst1);
	while (result != 1)
	{
		if (lst1)
		{
			perform_rrx(lst1);
			perform_rx(lst1);
			perform_sx(lst1);
		}
		movement_result(*lst1, *lst2);
		// if (ft_lstsize(*lst2) > 0)
		// {
		// 	perform_rrx(lst2);
		// 	perform_rx(lst2);
		// 	perform_sx(lst2);
		// }	
		// movement_result(*lst1, *lst2);
		perform_pb(lst1, lst2);
		movement_result(*lst1, *lst2);
		result = stack_ascending_checker(lst1);
	}
	perform_pa(lst1, lst2);
	movement_result(*lst1, *lst2);
	return (0);
}
