/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:16:35 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/28 17:57:15 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*ft_lstlast(t_elem *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next_number != NULL)
		lst = lst->next_number;
	return (lst);
}

int	ft_lstsize(t_elem *lst)
{
	t_elem	*current;
	int		count;

	current = lst;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next_number;
	}
	return (count);
}

void	ft_lstadd_front(t_elem **lst, t_elem *new_node)
{
	if (lst)
	{
		if (*lst)
			new_node->next_number = *lst;
		*lst = new_node;
	}
}

t_elem	*ft_lstnew(int number, char letter)
{
	t_elem	*new_lst;

	new_lst = malloc(sizeof(t_elem));
	if (!new_lst)
		return (0);
	new_lst->number = number;
	new_lst->stack_letter = letter;
	new_lst->position = 0;
	new_lst->is_above_center = 0;
	new_lst->cost_a = 0;
	new_lst->cost_b = 0;
	new_lst->total_cost = 0;
	new_lst->index = 0;
	new_lst->target_pos = NULL;
	new_lst->next_number = NULL;
	return (new_lst);
}

void	ft_lstadd_back(t_elem **lst, t_elem *new_node)
{
	t_elem	*last;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = *lst;
	while (last->next_number != NULL)
		last = last->next_number;
	last->next_number = new_node;
}
