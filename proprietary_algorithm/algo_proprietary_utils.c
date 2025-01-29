/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_proprietary_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:32:57 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/29 14:34:10 by luide-ca         ###   ########.fr       */
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

int	get_match_node_cost(t_elem **lst)
{
	int		cost;
	int		lst_size;
	t_elem	*current;

	cost = 0;
	current = *lst;
	lst_size = ft_lstsize(*lst);
	if (current->target_pos->is_above_center)
		cost += current->target_pos->position;
	else
		cost += (lst_size - current->target_pos->position);
	return (cost);
}

void	cal_cost(t_elem **lst)
{
	t_elem	*current;
	int		lst_size;
	int		cost;

	current = *lst;
	lst_size = ft_lstsize(*lst);
	cost = 0;
	while (current)
	{
		if (current->is_above_center)
			cost = current->position;
		else
			cost = lst_size - current->position;
		cost += get_match_node_cost(lst);
		if (current == get_biggest_node(lst) || \
			current == get_sec_biggest_node(lst) || \
			current == get_third_biggest_node(lst))
			cost -= 1;
		else if (current == get_smallest_node(lst))
			cost += 1;
		current->cost = cost;
		current = current->next_number;
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