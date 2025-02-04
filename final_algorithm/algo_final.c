/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:23:49 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/04 11:14:27 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ordered(t_elem *lst)
{
	t_elem	*current;

	if (lst == NULL)
		return (0);
	current = lst;
	while (current)
	{
		if (current->index > current->next_number->index)
			return (0);
		current = current->next_number;
	}
	return (1);
}

void	algo_case_3(t_elem **lst1, t_elem **lst2)
{
	t_elem	*lower_cost_node;
	int		lst_size2;

	move_elems_to_b(lst1, lst2);
	if (check_ordered(*lst1) == 0)
		algo_case_2(lst1);
	lst_size2 = ft_lstsize(*lst2);
	while (lst_size2 != 0)
	{
		lower_cost_node = ft_init_b(lst1, lst2);
		ft_move_b(lst1, lst2, lower_cost_node);
		lst_size2 = ft_lstsize(*lst2);	
	}
	update_pos(lst1);
	perform_final_ra_or_rra(lst1);
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