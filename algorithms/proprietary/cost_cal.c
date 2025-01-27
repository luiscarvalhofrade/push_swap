/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_cal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:46:17 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 16:51:18 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	inner_stack_cost(t_elem **lst)
{
	t_elem	*current;
	int		size_lst;

	current = *lst;
	size_lst = ft_lstsize(*lst);
	while (current)
	{
		if ((size_lst / 2) >= current->position)
			current->cost_inner = current->position;
		else if ((size_lst / 2) < current->position)
			current->cost_inner = current->position - size_lst;
		current = current->next_number;
	}
}

void	target_stack_cost(t_elem **lst)
{
	t_elem	*current;
	int		size_lst;

	current = *lst;
	size_lst = ft_lstsize(*lst);
	while (current)
	{
		if (current->target_pos == 0)
			current->cost_tar_stack = 0;
		else if ((size_lst / 2) >= current->target_pos)
			current->cost_tar_stack = current->target_pos;
		else if ((size_lst / 2) < current->target_pos)
			current->cost_tar_stack = current->target_pos - size_lst;
		current = current->next_number;
	}
}