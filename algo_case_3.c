/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:03:23 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/15 18:13:42 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_case_3(t_elem **lst1, t_elem **lst2)
{
	int	lst_size;

	lst_size = ft_lstsize(lst1);
	while (lst_size > 3)
	{
		px(lst1, lst2);
		lst_size--;
	}
	algo_case_2(lst1);
	def_current_pos(lst1, lst2);
	def_target_pos(lst2);
	
}