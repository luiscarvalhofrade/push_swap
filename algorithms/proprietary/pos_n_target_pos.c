/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_n_target_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:44:48 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 16:44:19 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_position(t_elem **lst)
{
	t_elem	*current;
	int		pos_i;

	current = *lst;
	pos_i = 1;
	while (current)
	{
		current->position = pos_i;
		pos_i++;
		current = current->next_number;
	}
}

void	update_tar_pos_for_elems_in_a(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current1;
	t_elem	*current2;
	t_elem	*best_match;

	current1 = *lst1;
	while(current1)
	{
		current2 = *lst2;
		best_match = NULL;
		while (current2)
		{
			if (current2->index > current1->index)
			{
				if (!best_match || current2->index < best_match->index)
					best_match = current2;
			}
			current2 = current2->next_number;
		}
		if (best_match)
			current1->target_pos = best_match->position;
		else
			current1->target_pos = 0;
		current1 = current1->next_number;
	}
}

void	update_tar_pos_for_elems_in_b(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current1;
	t_elem	*current2;
	t_elem	*best_match;

	current2 = *lst2;
	while(current2)
	{
		current1 = *lst1;
		best_match = NULL;
		while (current1)
		{
			if (current1->index > current2->index)
			{
				if (!best_match || current1->index < best_match->index)
					best_match = current1;
			}
			current1 = current1->next_number;
		}
		if (best_match)
			current2->target_pos = best_match->position;
		else
			current2->target_pos = 0;
		current2 = current2->next_number;
	}
}

void	update_pos_n_tar_pos(t_elem **lst1, t_elem **lst2)
{
	t_elem	*head;

	head = *lst1;
	if (lst1)
		update_pos(lst1);
	if (lst2)
		update_pos(lst2);
	if (head->stack_letter == 'a')
		update_tar_pos_for_elems_in_a(lst1, lst2);
	else
		update_tar_pos_for_elems_in_b(lst1, lst2);
}
