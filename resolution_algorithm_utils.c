/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_algorithm_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:27:11 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/06 13:27:12 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_ascending_checker(t_list **lst)
{
	t_list	*current;
	t_list	*next_node;

	current = *lst;
	while (current->next_number != NULL)
	{
		next_node = current->next_number;
		if (current->number > next_node->number)
			return (0);
		current = current->next_number;
	}
	return (1);
}

int	perform_px(t_list **lst)
{
	t_list	*current;
	t_list	*next_node;
	int		lst_len;
	int		comparison;

	current = *lst;
	comparison = 1;
	lst_len = ft_lstsize(*lst);
	while (current->next_number != NULL)
	{
		next_node = current->next_number;
		if (current->number > next_node->number)
			return (comparison);
		comparison++;
		current = current->next_number;
	}
	if (comparison != 1 && comparison != (lst_len - 1))
		return (1);
	return (0);
}

int	perform_sx(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = first->next_number;
	if (first->stack_letter == 'a')
	{
		if (first->number > second->number)
			return (1);
	}
	else
	{
		if (first->number < second->number)
			return (1);
	}
	return (0);
}

int	perform_rx(t_list **lst)
{
	t_list	*first;
	t_list	*current;

	first = *lst;
	current = first->next_number;
	if (first->stack_letter == 'a')
	{
		while (current->next_number != NULL)
		{
			if (first->number < current->number)
				return (0);
			current = current->next_number;
		}
	}
	else
	{
		while (current->next_number != NULL)
		{
			if (first->number > current->number)
				return (0);
			current = current->next_number;
		}
	}
	return (1);
}

int	perform_rrx(t_list **lst)
{
	t_list	*last;
	t_list	*current;

	current = *lst;
	last = ft_lstlast(*lst);
	if (last->stack_letter == 'a')
	{
		while (current->next_number != last)
		{
			if (last->number > current->number)
				return (0);
			current = current->next_number;
		}
	}
	else
	{
		while (current->next_number != last)
		{
			if (last->number < current->number)
				return (0);
			current = current->next_number;
		}
	}
	return (1);
}
