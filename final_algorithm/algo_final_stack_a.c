/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_final_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:35 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/04 11:11:00 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_target_pos_in_b(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current1;
	t_elem	*current2;
	t_elem	*best_match;

	current1 = *lst1;
	while (current1)
	{
		best_match = NULL;
		current2 = *lst2;
		while (current2)
		{
			if (current2->index < current1->index && \
				(best_match == NULL || current2->index > best_match->index))
				best_match = current2;
			current2 = current2->next_number;
		}
		if (best_match)
			current1->target_pos = best_match;
		else
			current1->target_pos = get_biggest_node(lst2);
		current1 = current1->next_number;
	}
}

void	cal_cost_a(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current;
	int		target_pos;

	current = *lst1;
	target_pos = current->target_pos->position;
	while (current)
	{
		if (current->position <= ((ft_lstsize(*lst1) - 1) / 2) && \
			target_pos <= ((ft_lstsize(*lst2) - 1) / 2))
			current->cost = ft_greater(current->position, target_pos);
		else if (current->position > (ft_lstsize(*lst1) - 1) / 2 \
			&& target_pos > (ft_lstsize(*lst2) - 1) / 2)
			current->cost = ft_greater((ft_lstsize(*lst1) - current->position), \
					(ft_lstsize(*lst2) - target_pos));
		else if (current->position <= (ft_lstsize(*lst1) - 1) / 2 \
			&& target_pos > (ft_lstsize(*lst2) - 1) / 2)
			current->cost = current->position + ft_lstsize(*lst2) \
				- target_pos;
		else
			current->cost = ft_lstsize(*lst1) - current->position \
				+ target_pos;
		current = current->next_number;
	}
}

t_elem	*ft_init_a(t_elem **lst1, t_elem **lst2)
{
	t_elem	*lower_cost = NULL;

	update_pos(lst1);
	update_pos(lst2);
	update_target_pos_in_b(lst1, lst2);
	cal_cost_a(lst1, lst2);
	lower_cost = get_lower_cost_node(lst1);
	return (lower_cost);
}

void	ft_move_a(t_elem **lst1, t_elem **lst2, t_elem *lower_cost_node)
{
	if (lower_cost_node->is_above_center == 1 && \
		lower_cost_node->target_pos->is_above_center == 1)
		perform_rr(lst2, lst1, lower_cost_node);
	else if (lower_cost_node->is_above_center == 0 && \
		lower_cost_node->target_pos->is_above_center == 0)
		perform_rrr(lst2, lst1, lower_cost_node);
	ft_finish_rotation(lst1, lower_cost_node, 'a');
	ft_finish_rotation(lst2, lower_cost_node->target_pos, 'b');
	px(lst1, lst2);
}

void	move_elems_to_b(t_elem **lst1, t_elem **lst2)
{	
	t_elem	*lower_cost_node;

	if (ft_lstsize(*lst1) > 3 && check_ordered(*lst1) == 0)
		px(lst1, lst2);
	if (ft_lstsize(*lst1) > 3 && check_ordered(*lst1) == 0)
		px(lst1, lst2);
	while (ft_lstsize(*lst1) > 3 && check_ordered(*lst1) == 0)
	{
		lower_cost_node = ft_init_a(lst1, lst2);
		ft_move_a(lst1, lst2, lower_cost_node);
	}
}
