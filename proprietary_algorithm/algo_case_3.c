/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:20:12 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/29 17:49:18 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_elems_to_b(t_elem **lst1, t_elem **lst2)
{
	int		lst_size;
	t_elem	*bigger_node;
	t_elem	*sec_big_node;
	t_elem	*third_big_node;
	t_elem	*current;

	current = *lst1;
	lst_size = ft_lstsize(*lst1);
	bigger_node = get_biggest_node(lst1);		
	sec_big_node = get_sec_biggest_node(lst1);
	third_big_node = get_third_biggest_node(lst1);
	while (lst_size > 3)
	{
		if (current == bigger_node || current == sec_big_node || \
			current == third_big_node)
		{
			current = current->next_number;
			rx(lst1);
		}
		else
		{
			current = current->next_number;
			px(lst1, lst2);
		}
		lst_size = ft_lstsize(*lst1);
	}
}

void	update_target_pos(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current1;
	t_elem	*current2;
	t_elem	*best_match;

	current2 = *lst2;
	best_match = NULL;
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

void	lower_cost_to_top(t_elem **lst)
{
	t_elem	*lower_cost_node;
	int		lst_size;
	int		pos;

	update_pos(lst);
	lower_cost_node = get_lower_cost_node(lst);
	pos = lower_cost_node->position;
	lst_size = ft_lstsize(*lst);
	if (lower_cost_node->is_above_center == 1)
	{
		while (pos != 0)
		{
			rx(lst);
			pos--;
		}
	}
	else if (lower_cost_node->is_above_center == 0)
	{
		while (pos != 0)
		{
			rrx(lst);
			pos = pos - (lst_size + 1);
		}
	}
}

void	perform_final_ra_or_rra(t_elem **lst)
{
	t_elem	*smallest_node;

	smallest_node = get_smallest_node(lst);	
	if (smallest_node->is_above_center == 1)
		rx(lst);
	else if (smallest_node->is_above_center == 0)
		rrx(lst);
}

void	algo_case_3(t_elem **lst1, t_elem **lst2)
{
	t_elem	*smallest_node;
	t_elem	*head;
	int		lst_size2;

	move_elems_to_b(lst1, lst2);
	if (check_ordered(*lst1) == 0)
		algo_case_2(lst1);
	lst_size2 = ft_lstsize(*lst2);
	while (lst_size2 != 0)
	{
		update_pos(lst1);
		update_pos(lst2);
		update_target_pos(lst1, lst2);
		printf("=== cost cal===\n");
		cal_cost(lst1, lst2);
		lower_cost_to_top(lst2);
		px(lst2, lst1);
		lst_size2 = ft_lstsize(*lst2);
	}
	update_pos(lst1);
	head = *lst1;
	smallest_node = get_smallest_node(lst1);
	if (!head || !smallest_node)
		return ;
	while (head != smallest_node)
		perform_final_ra_or_rra(lst1);
}
