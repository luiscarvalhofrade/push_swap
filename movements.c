/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:11:36 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/05 20:11:37 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_positions_top(t_list **lst)
{
	t_list	*tmp_head;
	t_list	*tmp_swap;
	t_list	*tmp_third;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp_head = *lst;
	tmp_swap = tmp_head->next_number;
	tmp_third = tmp_swap->next_number;
	tmp_head->next_number = tmp_third;
	*lst = tmp_swap;
	tmp_swap->next_number = tmp_head;
}

void	ss(t_list **lst1, t_list **lst2)
{
	if (!lst1)
		swap_positions_top(lst1);
	if (!lst2)
		swap_positions_top(lst2);
}

void	push_to_other_stack(t_list **lst1, t_list **lst2)
{
	t_list	*new_top_lst1;
	t_list	*new_top_lst2;

	if (ft_lstsize(*lst1) == 0)
		return ;
	new_top_lst2 = *lst1;
	new_top_lst1 = new_top_lst2->next_number;
	if (new_top_lst2->stack_letter == 'a')
		new_top_lst2->stack_letter = 'b';
	else
		new_top_lst2->stack_letter = 'a';
	new_top_lst2->next_number = NULL;
	ft_lstadd_front(lst2, new_top_lst2);
	*lst1 = new_top_lst1;
}

void	rotate_first_to_bottom(t_list **lst)
{
	t_list	*tmp_head;
	t_list	*new_top;
	t_list	*tmp_last;

	if (ft_lstsize(*lst) < 2)
		return ;
	tmp_head = *lst;
	new_top = tmp_head->next_number;
	tmp_last = ft_lstlast(*lst);
	tmp_last->next_number = tmp_head;
	tmp_head->next_number = NULL;
	*lst = new_top;
}

void	rr(t_list **lst1, t_list **lst2)
{
	if (!lst1)
		rotate_first_to_bottom(lst1);
	if (!lst2)
		rotate_first_to_bottom(lst2);
}

void	rotate_last_to_top(t_list **lst)
{
	t_list	*new_top;
	t_list	*new_second;
	t_list	*new_last;

	if (ft_lstsize(*lst) < 2)
		return ;
	new_second = *lst;
	new_top = ft_lstlast(*lst);
	new_last = *lst;
	while (new_last->next_number != new_top)
		new_last = new_last->next_number;
	new_last->next_number = NULL;
	new_top->next_number = new_second;
	*lst = new_top;
}

void	rrr(t_list **lst1, t_list **lst2)
{
	if (!lst1)
		rotate_last_to_top(lst1);
	if (!lst2)
		rotate_last_to_top(lst2);
}
