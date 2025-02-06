/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:23:49 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/06 11:10:41 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ordered(t_elem *lst)
{
	t_elem	*current;

	if (lst == NULL)
		return (0);
	current = lst;
	while (current->next_number)
	{
		if (current->index > current->next_number->index)
			return (0);
		current = current->next_number;
	}
	return (1);
}

void	final_algo(t_elem **lst1, t_elem **lst2)
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
