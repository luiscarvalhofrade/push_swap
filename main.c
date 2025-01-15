/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:56:44 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/15 16:51:31 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movement_result(t_elem *lst1, t_elem *lst2)
{
	int		i;
	int		j;
	t_elem	*current;
	t_elem	*currentb;

	current = lst1;
	printf("\n stack a\n\n");
	i = 0;
	while (current)
	{
		printf("[%c]no[%d]:%d\n", current->stack_letter, i, current->number);
		current = current->next_number;
		i++;
	}
	printf("\n stack b\n\n");
	j = 0;
	currentb = lst2;
	while (currentb)
	{
		printf("[%c]no[%d]:%d\n", currentb->stack_letter, j, currentb->number);
		currentb = currentb->next_number;
		j++;
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
	resolution_algorithm(&lsta, &lstb);
	movement_result(lsta, lstb);
	free_lst(lsta);
	free_lst(lstb);
	return (0);
}
