/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_aggregated.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:48:23 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 12:24:34 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	ss(t_elem **lst1, t_elem **lst2)
{
	t_elem	*tmp_head;
	t_elem	*tmp_swap;
	t_elem	*tmp_third;

	if (ft_lstsize(*lst1) < 2 && ft_lstsize(*lst2) < 2)
		return ;
	tmp_head = *lst1;
	tmp_swap = tmp_head->next_number;
	tmp_third = tmp_swap->next_number;
	tmp_head->next_number = tmp_third;
	*lst1 = tmp_swap;
	tmp_swap->next_number = tmp_head;
	tmp_head = *lst2;
	tmp_swap = tmp_head->next_number;
	tmp_third = tmp_swap->next_number;
	tmp_head->next_number = tmp_third;
	*lst2 = tmp_swap;
	tmp_swap->next_number = tmp_head;
	write(1, "ss\n", 3);
}

void	rr(t_elem **lst1, t_elem **lst2)
{
	t_elem	*tmp_head;
	t_elem	*new_top;
	t_elem	*tmp_last;

	if (ft_lstsize(*lst1) < 2 && ft_lstsize(*lst2) < 2)
		return ;
	tmp_head = *lst1;
	new_top = tmp_head->next_number;
	tmp_last = ft_lstlast(*lst1);
	tmp_last->next_number = tmp_head;
	tmp_head->next_number = NULL;
	*lst1 = new_top;
	tmp_head = *lst2;
	new_top = tmp_head->next_number;
	tmp_last = ft_lstlast(*lst2);
	tmp_last->next_number = tmp_head;
	tmp_head->next_number = NULL;
	*lst2 = new_top;
	write(1, "rr\n", 3);
}

void	rrr(t_elem **lst1, t_elem **lst2)
{
	t_elem	*new_top;
	t_elem	*new_second;
	t_elem	*new_last;

	if (ft_lstsize(*lst1) < 2 && ft_lstsize(*lst2) < 2)
		return ;
	new_second = *lst1;
	new_top = ft_lstlast(*lst1);
	new_last = *lst1;
	while (new_last->next_number != new_top)
		new_last = new_last->next_number;
	new_last->next_number = NULL;
	new_top->next_number = new_second;
	*lst1 = new_top;
	new_second = *lst2;
	new_top = ft_lstlast(*lst2);
	new_last = *lst2;
	while (new_last->next_number != new_top)
		new_last = new_last->next_number;
	new_last->next_number = NULL;
	new_top->next_number = new_second;
	*lst2 = new_top;
	write(1, "rrr\n", 4);
}
