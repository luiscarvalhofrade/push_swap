/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:03 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/05 20:05:04 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int number, char letter)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (0);
	new_lst->number = number;
	new_lst->stack_letter = letter;
	new_lst->next_number = NULL;
	return (new_lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

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

int	ft_nbr(char *nbr)
{
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	while (('0' <= *nbr && *nbr <= '9') && *nbr)
	{
		if (!('0' <= *nbr && *nbr <= '9'))
			return (0);
		nbr++;
	}
	return (1);
}
