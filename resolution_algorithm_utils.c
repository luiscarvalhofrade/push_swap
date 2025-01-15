/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_algorithm_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:27:11 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	perform_pa(t_elem **lst1, t_elem **lst2)
{
	int		lst_len;

	lst_len = ft_lstsize(*lst2);
	while (lst_len > 0)
	{
		px(lst2, lst1);
		lst_len--;
	}
	return (0);
}

int	perform_pb(t_elem **lst1, t_elem **lst2)
{
	t_elem	*current;
	t_elem	*next_node;
	int		lst_len;
	int		comparison;

	current = *lst1;
	comparison = 0;
	lst_len = ft_lstsize(*lst1);
	next_node = current->next_number;
	while (current->next_number != NULL && current->number < next_node->number)
	{
		comparison++;
		current = current->next_number;
		next_node = current->next_number;
	}
	if (comparison != 1 && comparison != (lst_len - 1))
	{
		while (comparison > 0)
		{
			px(lst1, lst2);
			comparison--;
		}
	}
	return (0);
}

int	perform_sx(t_elem **lst)
{
	t_elem	*first;
	t_elem	*second;

	first = *lst;
	second = first->next_number;
	if (first->stack_letter == 'a')
	{
		if (first->number > second->number)
		{
			sx(lst);
			return (1);
		}
	}
	else
	{
		if (first->number < second->number)
		{
			sx(lst);
			return (1);
		}
	}
	return (0);
}

int	perform_rx(t_elem **lst)
{
	int		first;
	char	stack_letter;
	t_elem	*current;

	if (!lst || !*lst)
		return (0);
	first = (*lst)->number;
	stack_letter = (*lst)->stack_letter;
	current = (*lst)->next_number;
	while (current)
	{
		if (stack_letter == 'a')
		{
			if (first < current->number)
				return (0);
		}
		else
		{
			if (first > current->number)
				return (0);
		}
		current = current->next_number;
	}
	rx(lst);
	return (1);
}

int	perform_rrx(t_elem **lst)
{
	t_elem	*last;
	t_elem	*current;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	last = ft_lstlast(*lst);
	while (current)
	{
		if (last->stack_letter == 'a')
		{
			if (last->number > current->number)
				return (0);
		}
		else
		{
			if (last->number < current->number)
				return (0);
		}
		current = current->next_number;
	}
	rrx(lst);
	return (1);
}
