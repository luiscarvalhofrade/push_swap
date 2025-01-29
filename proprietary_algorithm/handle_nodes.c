/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_proprietary_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:12:02 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/28 18:26:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*get_biggest_node(t_elem *lst)
{
	int		lst_size;
	t_elem	*current;
	t_elem	*biggest_node;

	lst_size = ft_lstsize(lst);
	current = lst;
	while (current)
	{
		if (current->index == lst_size)
		{
			biggest_node = current;
			return (biggest_node);
		}
		current = current->next_number;
	}
}

t_elem	*get_sec_biggest_node(t_elem *lst)
{
	int		lst_size;
	t_elem	*current;
	t_elem	*second_big_node;

	lst_size = ft_lstsize(lst);
	current = lst;
	while (current)
	{
		if (current->index == (lst_size - 1))
		{
			second_big_node = current;
			return (second_big_node);
		}
		current = current->next_number;
	}
}

t_elem	*get_third_biggest_node(t_elem *lst)
{
	int		lst_size;
	t_elem	*current;
	t_elem	*third_big_node;

	lst_size = ft_lstsize(lst);
	current = lst;
	while (current)
	{
		if (current->index == (lst_size - 1))
		{
			third_big_node = current;
			return (third_big_node);
		}
		current = current->next_number;
	}
}

t_elem	*get_smallest_node(t_elem *lst)
{
	t_elem	*current;
	t_elem	*smallest_node;

	current = lst;
	while (current)
	{
		if (current->index == 1)
		{
			smallest_node = current;
			return (smallest_node);
		}
		current = current->next_number;
	}
}
