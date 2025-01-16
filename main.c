/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:56:44 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/16 16:53:48 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movement_result(t_elem *lst1, t_elem *lst2)
{
	t_elem	*current;
	t_elem	*currentb;

	current = lst1;
	printf("\n stack a\n\n");
	while (current)
	{
		printf("[%c]no[%d]:%d, pos:%d\n", current->stack_letter, current->index, current->number, current->position);
		current = current->next_number;
	}
	printf("\n stack b\n\n");
	currentb = lst2;
	while (currentb)
	{
		printf("[%c]no[%d]:%d, pos:%d\n", current->stack_letter, current->index, current->number, current->position);
		currentb = currentb->next_number;
	}
	printf("\n===============\n");
}

void	free_lst(t_elem *lst)
{
	t_elem	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next_number;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	t_elem	*lsta;
	t_elem	*lstb;
	int		val_res;

	lsta = NULL;
	lstb = NULL;
	val_res = input_validator(argc, argv);
	if (val_res == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	lsta = stack_builder(argc, argv);
	if (!lsta || lsta == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	movement_result(lsta, lstb);
	resolution_algorithm(&lsta, &lstb);
	movement_result(lsta, lstb);
	free_lst(lsta);
	free_lst(lstb);
	return (0);
}
