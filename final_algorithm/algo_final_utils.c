/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_final_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:30:28 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/05 17:35:30 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_pos(t_elem **lst)
{
	t_elem	*current;
	int		i;
	int		center_line;

	current = *lst;
	center_line = ((ft_lstsize(*lst) - 1) / 2);
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

int	ft_greater(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}