/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_proprietary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:06:03 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/29 14:29:22 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
