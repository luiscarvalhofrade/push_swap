/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_aggregated.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:48:23 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	ss(t_elem **lst1, t_elem **lst2)
{
	if (lst1)
		sx(lst1);
	if (lst2)
		sx(lst2);
}

void	rr(t_elem **lst1, t_elem **lst2)
{
	if (lst1)
		rx(lst1);
	if (lst2)
		rx(lst2);
}

void	rrr(t_elem **lst1, t_elem **lst2)
{
	if (lst1)
		rrx(lst1);
	if (lst2)
		rrx(lst2);
}
