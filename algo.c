/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:11:14 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/22 12:12:25 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolution(t_elem **lst1, t_elem **lst2)
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
