/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:43:58 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 14:44:24 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo(t_elem **lst1, t_elem **lst2)
{
	int		lst_size1;
	int		lst_size2;
	t_elem	*small_cost;

	lst_size1 = ft_lstsize(*lst1);
	while (lst_size1 > 3)
	{
		define_target_pos_stack_a(lst1, lst2);
		cost_cal(lst2, lst1);
		small_cost = pick_smaller_cost(lst2);
		solve_elem(small_cost, lst1, lst2);
		lst_size1--;
	}
	algo_case_2(lst1);
	lst_size2 = ft_lstsize(*lst2);
	while (lst_size2 > 0)
	{
		define_target_pos_stack_b(lst1, lst2);
		cost_cal(lst1, lst2);
		small_cost = pick_smaller_cost(lst2);
		solve_elem(small_cost, lst1, lst2);
		lst_size2 = ft_lstsize(*lst2);
	}
}