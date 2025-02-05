/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:34:59 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/05 18:58:21 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_case_3(t_elem **lst1, t_elem **lst2)
{
	t_elem	*lower_cost_node;

	move_elems_to_b(lst1, lst2);
	if (check_ordered(*lst1) == 0)
		algo_case_2(lst1);
	while (ft_lstsize(*lst2) != 0)
	{
		lower_cost_node = ft_init_b(lst1, lst2);
		ft_move_b(lst1, lst2, lower_cost_node);
	}
	update_pos(lst1);
	perform_final_ra_or_rra(lst1);
}
