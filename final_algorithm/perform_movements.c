/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:43:22 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/30 17:19:25 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_final_ra_or_rra(t_elem **lst)
{
	t_elem	*smallest_node;
	int		pos;
	int		lst_size;

	smallest_node = get_smallest_node(lst);
	pos = smallest_node->position;
	lst_size = ft_lstsize(*lst);
	if (smallest_node->is_above_center == 1)
	{
		while (pos != 0)
		{
			rx(lst);
			pos--;
		}
	}
	else if (smallest_node->is_above_center == 0)
	{
		while (pos != 0)
		{
			rrx(lst);
			pos = pos - (lst_size + 1);
		}
	}
}

void	perform_rr(t_elem **lst1, t_elem **lst2, t_elem *lower_cost)
{
	t_elem	*current1;
	t_elem	*current2;

	current1 = *lst1;
	current2 = *lst2;
	while (current1 != lower_cost->target_pos && current2 != lower_cost)
		rr(lst1, lst2);
	update_pos(lst1);
	update_pos(lst2);
}

void	perform_rrr(t_elem **lst1, t_elem **lst2, t_elem *lower_cost)
{
	t_elem	*current1;
	t_elem	*current2;

	current1 = *lst1;
	current2 = *lst2;
	while (current1 != lower_cost->target_pos && current2 != lower_cost)
		rrr(lst1, lst2);
	update_pos(lst1);
	update_pos(lst2);
}