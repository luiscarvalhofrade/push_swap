/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_definer_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:46:22 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/21 13:03:29 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem *find_min_unvisited(t_elem *head) 
{
    t_elem	*min_node;
    int		min_value;

	min_value = INT_MAX;
	min_node = NULL;
    while (head) 
	{
        if (head->index == 0 && head->number < min_value) 
		{
            min_value = head->number;
            min_node = head;
        }
        head = head->next_number;
    }
    return (min_node);
}

void assign_index(t_elem *head, int current_index) 
{
	t_elem	*min_node;

    if (!head)
        return;
    min_node = find_min_unvisited(head);
    if (min_node) 
	{
        min_node->index = current_index;
        assign_index(head, current_index + 1);
    }
}