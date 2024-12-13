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

int	get_highest_bit(t_list **lst)
{
	int		current_bit;
	int		num;
	int		max_pos;
	t_list	*current;

	current = *lst;
	max_pos = 0;
	while (current)
	{
		num = (current)->number;
		current_bit = 0;
		while (num > 0)
		{
			num >>= 1;
			current_bit++;
		}
		if (max_pos < current_bit)
			max_pos = current_bit;
		current = current->next_number;
	}
	return (max_pos);
}

int	stack_checker(t_list **lst)
{
	t_list	*current;
	t_list	*next_node;
	char	stack_letter;

	current = *lst;
	stack_letter = (current)->stack_letter;
	while (current->next_number != NULL)
	{
		if (stack_letter == 'a')
		{
			next_node = current->next_number;
			if (current->number > next_node->number)
				return (0);
		}
		else
		{
			next_node = current->next_number;
			if (current->number < next_node->number)
				return (0);
		}
		current = current->next_number;
	}
	return (1);
}

void	resolution_algorithm(t_list **lst1, t_list **lst2)
{
	t_list	*current_node;
	int		lst1_size;
	int		pos;
	int		max_pos;

	pos = 0;
	lst1_size = ft_lstsize(*lst1);
	max_pos = get_highest_bit(lst1);
	while (pos < max_pos)
	{
		while (lst1_size > 0)
		{
			current_node = *lst1;
			if ((current_node)->number & (1 << pos))
				rx(lst1);
			else
				px(lst1, lst2);
			lst1_size--;
		}
		perform_pa(lst1, lst2);
		lst1_size = ft_lstsize(*lst1);
		pos++;
	}
}
