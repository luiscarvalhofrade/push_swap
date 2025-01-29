/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:20:12 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/29 14:38:09 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_target_pos(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current1;
	t_elem	*current2;
	t_elem	*best_match;

	current2 = *lst2;
	while (current2)
	{
		current1 = *lst1;
		while (current1)
		{
			if (current1->index > current2->index && \
				(!best_match || current1->index < best_match->index))
				best_match = current1;
			current1 = current1->next_number;
		}
		if (best_match)
			current2->target_pos = best_match;
		else
			current2->target_pos = get_smallest_node(lst1);
		current2 = current2->next_number;
	}
}

void	move_elems_to_b(t_elem **lst1, t_elem **lst2)
{
	int		size_lst;
	t_elem	*bigger_node;
	t_elem	*sec_bigger_node;
	t_elem	*smallest_node;
	t_elem	*current;

	current = *lst1;
	size_lst = ft_lstsize(*lst1);
	bigger_node = get_biggest_node(lst1);
	sec_bigger_node = get_sec_biggest_node(lst1);
	smallest_node = get_smallest_node(lst1);
	while (size_lst > 3)
	{
		if (current == bigger_node || current == sec_bigger_node || \
			current == smallest_node)
			rx(lst1);
		px(lst1, lst2);
		current = current->next_number;
	}
}

void	lower_cost_to_top(t_elem **lst)
{
	t_elem	*smallest_node;
	t_elem	*current;

	current = *lst;
	update_pos(lst);
	smallest_node = get_smallest_node(lst);
	if (smallest_node->is_above_center)
	{
		while (current->position != smallest_node->position)
			rx(lst);
	}
	else if (!smallest_node->is_above_center)
	{
		while (current->position != smallest_node->position)
			rrx(lst);
	}
}

void	perform_final_ra_or_rra(t_elem **lst)
{
	t_elem	*smallest_node;

	smallest_node = get_smallest_node(lst);	
	if (smallest_node->is_above_center)
		rx(lst);
	else if (!(smallest_node->is_above_center))
		rrx(lst);
}

void	algo_case_3(t_elem **lst1, t_elem **lst2)
{
	t_elem	*smallest_node;
	t_elem	*head;

	move_elems_to_b(lst1, lst2);
	if (check_ordered(*lst1) == 0)
		algo_case_2(lst1);
	while (lst2 != NULL)
	{
		update_pos(lst1);
		update_pos(lst2);
		update_target_pos(lst1, lst2);
		cal_cost(lst2);
		lower_cost_to_top(lst1);
		px(lst2, lst1);
	}
	update_pos(lst1);
	head = *lst1;
	smallest_node = get_smallest_node(lst1);
	while (head != smallest_node)
		perform_final_ra_or_rra(lst1);
}
