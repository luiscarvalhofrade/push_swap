/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:27:03 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/06 13:27:04 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	resolution_algorithm(t_list **lst)
{
	int	result;
	while ((result = stack_ascending_checker(lst)) != 1)
	{
		perform_rx(lst);
		perform_rrx(lst);
		perform_sx(lst);
	}
}