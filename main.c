/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:56:44 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/22 15:30:38 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movement_result(t_elem *lst1, t_elem *lst2)
{
	t_elem	*current;
	//t_elem	*currentb;

	current = lst1;
	printf("\n stack a\n\n");
	while (current)
	{
		printf("[%c]no[%d]:%d, pos:%d\n", current->stack_letter, current->index, current->number, current->position);
		current = current->next_number;
	}
	printf("\n stack b\n\n");
	if (lst2)
	// {
	// 	currentb = lst2;
	// 	while (currentb)
	// 	{
	// 		printf("[%c]no[%d]:%d, pos:%d\n", current->stack_letter, current->index, current->number, current->position);
	// 		currentb = currentb->next_number;
	// 	}
	// }
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
	t_elem	*lsta1;
	t_elem	*lstb1;
	t_elem	*lsta2;
	t_elem	*lstb2;
	int		val_res;

	lsta1 = NULL;
	lstb1 = NULL;
	lsta2 = NULL;
	lstb2 = NULL;

	val_res = input_validator(argc, argv);
	if (val_res == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	lsta1 = stack_builder(argc, argv);
	lsta2 = stack_builder(argc, argv);
	if ((!lsta1 || lsta1 == 0) && (!lsta2 || lsta2 == 0))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	update_pos_n_target_pos(&lsta1, &lstb1);
	movement_result(lsta1, lstb1);
	printf("==radix_algo==\n");
	radix_algo(&lsta1, &lstb1);
	movement_result(lsta1, lstb1);
	printf("==mia_algo==\n");
	mia_algo(&lsta2, &lstb2);
	movement_result(lsta2, lstb2);
	free_lst(lsta1);
	free_lst(lstb1);
	free_lst(lsta2);
	free_lst(lstb2);
	return (0);
}
