/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:27:03 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/28 15:12:45 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_highest_bit(t_elem **lst)
{
	int		current_bit;
	int		num;
	int		max_pos;
	t_elem	*current;

	current = *lst;
	max_pos = 0;
	while (current)
	{
		num = (current)->index;
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

int	stack_checker(t_elem **lst)
{
	t_elem	*current;
	t_elem	*next_node;
	char	stack_letter;

	current = *lst;
	stack_letter = (current)->stack_letter;
	while (current->next_number != NULL)
	{
		if (stack_letter == 'a')
		{
			next_node = current->next_number;
			if (current->index > next_node->index)
				return (0);
		}
		else
		{
			next_node = current->next_number;
			if (current->index < next_node->index)
				return (0);
		}
		current = current->next_number;
	}
	return (1);
}

void	radix_algo(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current_node;
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
			if ((current_node)->index & (1 << pos))
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
