/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_proprietary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:06:03 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/28 18:28:55 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	proprietary_algo(t_elem **lst1, t_elem **lst2)
{
	t_elem	*smallest_node;

	move_elems_to_b(lst1, lst2);
	if (!check_ordered(lst1))
		algo_case_2(lst1);
	while (lst2 != NULL)
	{
		update_pos_n_target_pos(lst1, lst2);
		set_cost(lst1, lst2);
		lower_cost_to_top(lst1, lst2);
		px(lst2, lst1);
	}
	update_pos_n_target_pos(lst1, lst2);
	smallest_node = get_smaller_node(lst1);
	while (*lst1 != smallest_node)
		perform_ra_or_rra(lst1);
}
