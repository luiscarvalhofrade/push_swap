/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:35 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/06 11:50:34 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	update_target_pos_in_b(t_elem **lst1, t_elem **lst2)
{
	t_elem	*no1;
	t_elem	*no2;
	t_elem	*target;
	long	best_match;

	no1 = *lst1;
	while (no1)
	{
		best_match = LONG_MIN;
		no2 = *lst2;
		while (no2)
		{
			if (no2->index < no1->index && no2->index > best_match)
			{
				best_match = no2->index;
				target = no2;
			}
			no2 = no2->next_number;
		}
		if (best_match == LONG_MIN)
			no1->target_pos = get_biggest_node(lst2);
		else
			no1->target_pos = target;
		no1 = no1->next_number;
	}
}

static void	cal_cost_a(t_elem **lst1, t_elem **lst2)
{
	t_elem	*no;

	no = *lst1;
	while (no)
	{
		if (no->position <= ((ft_lstsize(*lst1) - 1) / 2) && \
			no->target_pos->position <= ((ft_lstsize(*lst2) - 1) / 2))
			no->cost = ft_greater(no->position, no->target_pos->position);
		else if (no->position > (ft_lstsize(*lst1) - 1) / 2 \
			&& no->target_pos->position > (ft_lstsize(*lst2) - 1) / 2)
			no->cost = ft_greater((ft_lstsize(*lst1) - no->position), \
					(ft_lstsize(*lst2) - no->target_pos->position));
		else if (no->position <= (ft_lstsize(*lst1) - 1) / 2 \
			&& no->target_pos->position > (ft_lstsize(*lst2) - 1) / 2)
			no->cost = no->position + ft_lstsize(*lst2) \
				- no->target_pos->position;
		else
			no->cost = ft_lstsize(*lst1) - no->position \
				+ no->target_pos->position;
		no = no->next_number;
	}
}

static t_elem	*ft_init_a(t_elem **lst1, t_elem **lst2)
{
	t_elem	*lower_cost;

	update_pos(lst1);
	update_pos(lst2);
	update_target_pos_in_b(lst1, lst2);
	cal_cost_a(lst1, lst2);
	lower_cost = get_lower_cost_node(lst1);
	return (lower_cost);
}

static void	ft_move_a(t_elem **lst1, t_elem **lst2, t_elem *lower_cost_node)
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
