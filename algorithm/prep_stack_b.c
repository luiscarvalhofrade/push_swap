/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:03:49 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/06 11:49:58 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_target_pos_in_a(t_elem **lst1, t_elem **lst2)
{
	t_elem	*no1;
	t_elem	*no2;
	t_elem	*target;
	long	best_match;

	no2 = *lst2;
	while (no2)
	{
		best_match = LONG_MAX;
		no1 = *lst1;
		while (no1)
		{
			if (no1->index > no2->index && no1->index < best_match)
			{
				best_match = no1->index;
				target = no1;
			}
			no1 = no1->next_number;
		}
		if (best_match == LONG_MAX)
			no2->target_pos = get_smallest_node(lst1);
		else
			no2->target_pos = target;
		no2 = no2->next_number;
	}
}

static void	cal_cost_b(t_elem **lst1, t_elem **lst2)
{
	t_elem	*no;

	no = *lst2;
	while (no)
	{
		if (no->position <= ((ft_lstsize(*lst2) - 1) / 2) && \
			no->target_pos->position <= ((ft_lstsize(*lst1) - 1) / 2))
			no->cost = ft_greater(no->position, no->target_pos->position);
		else if (no->position > (ft_lstsize(*lst2) - 1) / 2 \
			&& no->target_pos->position > (ft_lstsize(*lst1) - 1) / 2)
			no->cost = ft_greater((ft_lstsize(*lst2) - no->position), \
					(ft_lstsize(*lst1) - no->target_pos->position));
		else if (no->position <= (ft_lstsize(*lst1) - 1) / 2 \
			&& no->target_pos->position > (ft_lstsize(*lst1) - 1) / 2)
			no->cost = no->position + ft_lstsize(*lst1) \
				- no->target_pos->position;
		else
			no->cost = ft_lstsize(*lst2) - no->position \
				+ no->target_pos->position;
		no = no->next_number;
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
