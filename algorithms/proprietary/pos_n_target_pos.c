/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_n_target_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:44:48 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 14:45:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	define_target_pos_stack_a(t_elem **lst1, t_elem **lst2)
{  
	t_elem	*current1;
	t_elem	*current2;
	int		size1;

	current1 = *lst1;
	size1 = ft_lstsize(*lst1);
	while (size1 > 3)
	{
		current2 = *lst2;
		current1->target_pos = 0;
		while (current2)
		{
			if (current1->index > current2->index)
				current1->target_pos = current2->position;
			current2 = current2->next_number;
		}
		size1--;
		current1 = current1->next_number;
	}
}

void	define_target_pos_stack_b(t_elem **lst1, t_elem **lst2)
{  
	t_elem	*current1;
	t_elem	*current2;

	current2 = *lst2;
	while (current2)
	{
		current1 = *lst1;
		current2->target_pos = 0;
		while (current1)
		{
			if (current2->index > current1->index)
				current2->target_pos = current1->position + 1;
			current1 = current1->next_number;
		}
		current2 = current2->next_number;
	}
}