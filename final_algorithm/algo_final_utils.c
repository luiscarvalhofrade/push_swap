/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_final_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:28 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/04 11:11:32 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_pos(t_elem **lst)
{
	t_elem	*current;
	int		i;
	int		center_line;
	int		lst_size;

	current = *lst;
	lst_size = ft_lstsize(*lst);
	center_line = (lst_size / 2);
	i = 0;
	while (current)
	{
		current->position = i;
		if (current->position <= center_line)
			current->is_above_center = 1;
		else if (current->position > center_line)
			current->is_above_center = 0;
		i++;
		current = current->next_number;
	}
}

t_elem	*get_lower_cost_node(t_elem **lst)
{
	t_elem	*current;
	t_elem	*lower_cost_node;
	int		temp_min;

	current = *lst;
	temp_min = current->cost;
	lower_cost_node = current;
	while (current)
	{
		if (current->cost < temp_min)
		{
			temp_min = current->cost;
			lower_cost_node = current;
		}
		current = current->next_number;
	}
	return (lower_cost_node);
}

void	ft_finish_rotation(t_elem **lst, t_elem *lower_cost, char c)
{
	while (*lst != lower_cost)
	{
		if (c == 'a')
		{
			if (lower_cost->is_above_center == 1)
				rx(lst);
			else
				rrx(lst);
		}
		else
		{
			if (lower_cost->is_above_center == 1)
				rx(lst);
			else
				rrx(lst);
		}
	}
}

int	ft_greater(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}