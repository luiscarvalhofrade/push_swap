/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos_n_target_pos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:05:21 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 14:14:07 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_pos(t_elem **lst)
{
	t_elem	*current;
	int		i;

	current = *lst;
	i = 0;
	while (current)
	{
		current->position = i;
		i++;
		current = current->next_number;
	}
}

void	update_target_pos(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current1;
	t_elem	*current2;
	t_elem	*best_match;

	current2 = *lst2;
	while (current2)
	{
		best_match = NULL;
		current1 = *lst1;
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

void	update_pos_n_target_pos(t_elem **lst1, t_elem **lst2)
{
	if (lst1)
		update_pos(lst1);
	if (lst2)
	{
		update_pos(lst2);
		update_target_pos(lst1, lst2);
	}
}
