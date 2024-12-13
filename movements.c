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

void	sx(t_list **lst)
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
	if (tmp_swap->stack_letter == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	px(t_list **lst1, t_list **lst2)
{
	t_list	*new_top_lst1;
	t_list	*new_top_lst2;
	char	stack_letter;

	if (ft_lstsize(*lst1) == 0)
		return ;
	new_top_lst2 = *lst1;
	stack_letter = (new_top_lst2)->stack_letter;
	new_top_lst1 = new_top_lst2->next_number;
	if (new_top_lst2->stack_letter == 'a')
		new_top_lst2->stack_letter = 'b';
	else
		new_top_lst2->stack_letter = 'a';
	new_top_lst2->next_number = NULL;
	ft_lstadd_front(lst2, new_top_lst2);
	*lst1 = new_top_lst1;
	if (stack_letter == 'a')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

void	rx(t_list **lst)
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
	if (new_top->stack_letter == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrx(t_list **lst)
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
	if (new_top->stack_letter == 'a')
		write(1, "rra\n", 2);
	else
		write(1, "rrb\n", 2);
}
