/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:03:23 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/22 12:13:34 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*pick_smaller_cost(t_elem **lst)
{
	t_elem	*current;
	t_elem	*min_elem;
	int		min_cost;

	current = *lst;
	min_elem = NULL;
	min_cost = INT_MAX;
	while (current)
	{
		if (current->total_cost < min_cost)
		{
			min_cost = current->total_cost;
			min_elem = current;
		}
		current = current->next_number;
	}
	return (min_elem);
}

void	solve_elem(t_elem *small_cost, t_elem **lst1, t_elem **lst2)
{
	int	cost_a;
	int	cost_b;

	cost_a = small_cost->cost_a;
	cost_b = small_cost->cost_b;
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(lst1, lst2);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		rr(lst1, lst2);
		cost_a--;
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrx(lst2);
		cost_b++;
	}
	while (cost_a < 0)
	{
		rrx(lst1);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rx(lst2);
		cost_b--;
	}
	while (cost_a > 0)
	{
		rx(lst1);
		cost_a--;
	}
	px(lst2, lst1);
}

void	ra_or_rra(t_elem **lst)
{
	t_elem	*head;
	int		i;
	int		total_mov;

	head = *lst;
	i = head->index;
	total_mov = (i - 1);
	while (total_mov > 0)
	{
		rrx(lst);
		total_mov--;
	}
}

void	algo_case_3(t_elem **lst1, t_elem **lst2)
{
	int		lst_size1;
	int		lst_size2;
	t_elem	*small_cost;

	lst_size1 = ft_lstsize(*lst1);
	while (lst_size1 > 3)
	{
		px(lst1, lst2);
		lst_size1--;
	}
	algo_case_2(lst1);
	lst_size2 = ft_lstsize(*lst2);
	while (lst_size2 != 0)
	{
		update_pos_n_target_pos(lst1, lst2);
		cost_cal(lst1, lst2);
		small_cost = pick_smaller_cost(lst2);
		solve_elem(small_cost, lst1, lst2);
		lst_size2 = ft_lstsize(*lst2);
	}
	ra_or_rra(lst1);
}
