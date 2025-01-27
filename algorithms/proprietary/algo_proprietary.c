/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_proprietary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:29:03 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 16:24:55 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	proprietary_algo(t_elem **lst1, t_elem **lst2)
{
	int	lst_size;

	lst_size = ft_lstsize(*lst1);
	if (lst_size == 2)
	{
		algo_case_1(lst1);
		return ;
	}
	else if (lst_size == 3)
	{
		algo_case_2(lst1);
		return ;
	}
	else if (lst_size > 3)
	{
		algo_case_3(lst1, lst2);
		return ;
	}
	return ;
}
