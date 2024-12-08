/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_aggregated.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:48:23 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/08 16:48:24 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	ss(t_list **lst1, t_list **lst2)
{
	if (lst1)
		sx(lst1);
	if (lst2)
		sx(lst2);
}

void	rr(t_list **lst1, t_list **lst2)
{
	if (lst1)
		rx(lst1);
	if (lst2)
		rx(lst2);
}

void	rrr(t_list **lst1, t_list **lst2)
{
	if (lst1)
		rrx(lst1);
	if (lst2)
		rrx(lst2);
}
