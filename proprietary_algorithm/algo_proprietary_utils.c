/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_proprietary_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:32:57 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/28 18:35:57 by luide-ca         ###   ########.fr       */
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