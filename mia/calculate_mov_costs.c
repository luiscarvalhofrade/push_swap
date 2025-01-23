/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_mov_costs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:17:05 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/22 15:26:07 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_b_cal(t_elem **lst)
{
	t_elem	*current;
	int		size_lst;

	current = *lst;
	size_lst = ft_lstsize(*lst);
	while (current)
	{
		if (current->position == 0)
			current->cost_b = 0;
		else if ((size_lst / 2) >= current->position)
			current->cost_b = current->position;
		else if ((size_lst / 2) < current->position)
			current->cost_b = (-1) * (size_lst - current->position);
		//printf("index: %d, cost_b: %d\n", current->index, current->cost_b);
		current = current->next_number;
	}
}

void	cost_a_cal(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current;
	int		size_lst;

	current = *lst2;
	size_lst = ft_lstsize(*lst1);
	while (current)
	{
		if (current->target_pos == 0)
			current->cost_a = 0;
		else if ((size_lst / 2) >= current->target_pos)
			current->cost_a = current->target_pos;
		else if ((size_lst / 2) < current->target_pos)
			current->cost_a = (-1) * (size_lst - current->target_pos);
		//("index: %d, cost_a: %d\n", current->index, current->cost_a);
		current = current->next_number;
	}
}

void	total_cost_cal(t_elem **lst)
{
	t_elem	*current;

	current = *lst;
	while (current)
	{
		current->total_cost = abs(current->cost_a) + abs(current->cost_b);
		//printf("index: %d, cost_total: %d\n", current->index, current->total_cost);
		current = current->next_number;
	}
}

void	cost_cal(t_elem **lst1, t_elem **lst2)
{
	//printf("\n=======cost b=======\n");
	cost_b_cal(lst2);
	//printf("\n=======cost a=======\n");
	cost_a_cal(lst1, lst2);
	//printf("\n========cost t======\n");
	total_cost_cal(lst2);
	//printf("\n===============\n");
}
