/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:19:34 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/05 18:56:26 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_case_1(t_elem **lst)
{
	t_elem	*current;
	t_elem	*next;

	current = *lst;
	next = current->next_number;
	if (current->index > next->index)
		sx(lst);
	return ;
}
