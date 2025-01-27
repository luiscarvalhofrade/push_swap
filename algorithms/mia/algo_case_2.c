/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:03:20 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 14:14:28 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_case_2(t_elem **lst)
{
	t_elem	*first;
	t_elem	*second;
	t_elem	*third;

	first = *lst;
	second = first->next_number;
	third = second->next_number;
	if (first->index > second->index && first->index > third->index)
		rx(lst);
	if (second->index > first->index && second->index > third->index)
		rrx(lst);
	first = *lst;
	second = first->next_number;
	if (first->index > second->index)
		sx(lst);
	return ;
}
