/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_final_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:03:49 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/04 13:50:02 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_target_pos_in_a(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current1;
	t_elem	*current2;
	t_elem	*best_match;

	current2 = *lst2;
	while (current2)
	{
		best_match = NULL;
		current1 = *lst1;
		while (current1)
		{
			if (current1->index > current2->index && \
				(best_match == NULL || current1->index < best_match->index))
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

void	cal_cost_b(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current;
	int		target_pos;

	current = *lst2;
	target_pos = current->target_pos->position;
	while (current)
	{
		if (current->position <= ((ft_lstsize(*lst2) - 1) / 2) && \
			target_pos <= ((ft_lstsize(*lst1) - 1) / 2))
			current->cost = ft_greater(current->position, target_pos);
		else if (current->position > (ft_lstsize(*lst2) - 1) / 2 \
			&& target_pos > (ft_lstsize(*lst1) - 1) / 2)
			current->cost = ft_greater((ft_lstsize(*lst2) - current->position), \
					(ft_lstsize(*lst1) - target_pos));
		else if (current->position <= (ft_lstsize(*lst1) - 1) / 2 \
			&& target_pos > (ft_lstsize(*lst1) - 1) / 2)
			current->cost = current->position + ft_lstsize(*lst1) \
				- target_pos;
		else
			current->cost = ft_lstsize(*lst2) - current->position \
				+ target_pos;
		current = current->next_number;
	}
}

t_elem	*ft_init_b(t_elem **lst1, t_elem **lst2)
{
	t_elem	*lower_cost;

	update_pos(lst1);
	update_pos(lst2);
	ft_target_pos_in_a(lst1, lst2);
	cal_cost_b(lst1, lst2);
	lower_cost = get_lower_cost_node(lst2);
	return (lower_cost);
}

void	ft_move_b(t_elem **lst1, t_elem **lst2, t_elem *lower_cost_node)
{
	if (lower_cost_node->is_above_center == 1 && \
		lower_cost_node->target_pos->is_above_center == 1)
		perform_rr(lst1, lst2, lower_cost_node);
	else if (lower_cost_node->is_above_center == 0 && \
		lower_cost_node->target_pos->is_above_center == 0)
		perform_rrr(lst1, lst2, lower_cost_node);
	ft_finish_rotation(lst2, lower_cost_node, 'b');
	ft_finish_rotation(lst1, lower_cost_node->target_pos, 'a');
	px(lst2, lst1);
}