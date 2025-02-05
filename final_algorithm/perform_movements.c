/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:43:22 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/05 16:16:11 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_final_ra_or_rra(t_elem **lst)
{
	t_elem	*smallest_node;

	smallest_node = get_smallest_node(lst);
	if (smallest_node->is_above_center == 1)
	{
		while (*lst != smallest_node)
			rx(lst);
	}
	else if (smallest_node->is_above_center == 0)
	{
		while (*lst != smallest_node)
			rrx(lst);
	}
}

void	perform_rr(t_elem **lst1, t_elem **lst2, t_elem *lower_cost)
{
	while (*lst1 != lower_cost->target_pos && *lst2 != lower_cost)
		rr(lst1, lst2);
	update_pos(lst1);
	update_pos(lst2);
}

void	perform_rrr(t_elem **lst1, t_elem **lst2, t_elem *lower_cost)
{
	while (*lst1 != lower_cost->target_pos && *lst2 != lower_cost)
		rrr(lst1, lst2);
	update_pos(lst1);
	update_pos(lst2);
}