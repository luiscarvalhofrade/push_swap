/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:12:02 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/29 13:51:19 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*get_biggest_node(t_elem **lst)
{
	t_elem	*current;
	t_elem	*biggest_node;
	int		temp_max;

	current = *lst;
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

t_elem	*get_sec_biggest_node(t_elem **lst)
{
	t_elem	*current;
	t_elem	*biggest_node;
	t_elem	*sec_big_node;

	current = *lst;
	biggest_node = get_biggest_node(lst);
	sec_big_node = NULL;
	while (current)
	{
		if ((current != biggest_node) && (sec_big_node == NULL
				|| current->index > sec_big_node->index))
			sec_big_node = current;
		current = current->next_number;
	}
	return (sec_big_node);
}

t_elem	*get_third_biggest_node(t_elem **lst)
{
	t_elem	*current;
	t_elem	*biggest_node;
	t_elem	*sec_big_node;
	t_elem	*third_big_node;

	current = *lst;
	biggest_node = get_biggest_node(lst);
	sec_big_node = get_sec_biggest_node(lst);
	third_big_node = NULL;
	while (current)
	{
		if ((current != biggest_node) && (current != sec_big_node) && \
			(third_big_node == NULL || current->index > third_big_node->index))
			third_big_node = current;
		current = current->next_number;
	}
	return (third_big_node);
}

t_elem	*get_smallest_node(t_elem **lst)
{
	t_elem	*current;
	t_elem	*smallest_node;
	int		temp_min;

	current = *lst;
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
