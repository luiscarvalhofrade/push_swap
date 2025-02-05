/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:12:02 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/05 18:49:53 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*get_biggest_node(t_elem **lst)
{
	t_elem	*current;
	t_elem	*biggest_node;
	int		temp_max;

	current = *lst;
	biggest_node = current;
	temp_max = current->index;
	while (current)
	{
		if (current->index > temp_max)
		{
			temp_max = current->index;
			biggest_node = current;
		}
		current = current->next_number;
	}
	return (biggest_node);
}

t_elem	*get_smallest_node(t_elem **lst)
{
	t_elem	*current;
	t_elem	*smallest_node;
	int		temp_min;

	current = *lst;
	smallest_node = current;
	temp_min = current->index;
	while (current)
	{
		if (current->index < temp_min)
		{
			temp_min = current->index;
			smallest_node = current;
		}
		current = current->next_number;
	}
	return (smallest_node);
}
