/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_proprietary_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:32:57 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/29 23:10:12 by luide-ca         ###   ########.fr       */
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

int	get_match_node_cost(t_elem **lst1, t_elem **lst2)
{
	int		cost;
	int		lst_size1;
	t_elem	*current;

	cost = 0;
	current = *lst2;
	lst_size1 = ft_lstsize(*lst1);
	if (current->target_pos->is_above_center == 1)
		cost += current->target_pos->position;
	else
		cost += (lst_size1 - current->target_pos->position);
	return (cost);
}

void	cal_cost(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current2;
	int		lst_size2;
	int		cost;

	current2 = *lst2;
	lst_size2 = ft_lstsize(*lst2);
	cost = 0;
	while (current2)
	{
		if (current2->is_above_center == 1)
			cost = current2->position;
		else
			cost = lst_size2 - current2->position;
		cost += get_match_node_cost(lst1, lst2);
		if (current2 == get_biggest_node(lst2) || \
			current2 == get_sec_biggest_node(lst2) || \
			current2 == get_third_biggest_node(lst2))
			cost -= 1;
		else if (current2 == get_smallest_node(lst2))
			cost += 1;
		current2->cost = cost;
		current2 = current2->next_number;
	}
}

int	check_ordered(t_elem *lst)
{
	t_elem	*current;

	if (lst == NULL)
		return (0);
	current = lst;
	while (current)
	{
		if (current->index > current->next_number->index)
			return (0);
		current = current->next_number;
	}
	return (1);
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