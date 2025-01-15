/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:11:45 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
