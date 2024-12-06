/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:56:44 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/05 18:56:46 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int j;
	t_list *lsta;
	t_list *lstb;
	t_list *current;
	t_list *current_b;

	i = 0;
	j = 0;
	lsta = NULL;
	lstb = NULL;
	if (argc < 3)
		return (printf("Error\n"));
	lsta = stack_builder(argc, argv);
	if (!lsta || lsta == 0)
		return (printf("Error\n"));
	current = lsta;
	printf("\n stack a\n\n");
	while (current)
	{
		printf("stack[%c]node[%d]: %d\n", current->stack_letter, i, current->number);
		current = current->next_number;
		i++;
	}
	printf("\nstack b\n\n");
	if (lstb)
	{
		current_b = lstb;
		while (current)
		{
			printf("stack[%c]node[%d]: %d\n", current_b->stack_letter, j, current_b->number);
			current_b = current_b->next_number;
			j++;
		}
	}
	push_to_other_stack(&lsta, &lstb);
	push_to_other_stack(&lsta, &lstb);
	push_to_other_stack(&lsta, &lstb);
	push_to_other_stack(&lsta, &lstb);
	push_to_other_stack(&lsta, &lstb);
	push_to_other_stack(&lstb, &lsta);
	push_to_other_stack(&lstb, &lsta);
	printf("\n here I pushed one value from stak a to b\n\n");
	i = 0;
	j = 0;
	current = lsta;
	printf("stack a\n\n");
	while (current)
	{
		printf("stack[%c]node[%d]: %d\n", current->stack_letter, i, current->number);
		current = current->next_number;
		i++;
	}
	current_b = lstb;
	printf("\nstack b\n\n");
	while (current_b)
	{
		printf("stack[%c]node[%d]: %d\n", current_b->stack_letter, j, current_b->number);
		current_b = current_b->next_number;
		j++;
	}

	printf("\n swap here \n\n");
	swap_positions_top(&lsta);
	i = 0;
	current = lsta;
	while (current)
	{
		printf("stack[%c]node[%d]: %d\n", current->stack_letter, i, current->number);
		current = current->next_number;
		i++;
	}
	printf("\n last to top here \n\n");
	rotate_last_to_top(&lsta);
	i = 0;
	current = lsta;
	while (current)
	{
		printf("stack[%c]node[%d]: %d\n", current->stack_letter, i, current->number);
		current = current->next_number;
		i++;
	}
	printf("\n first to bottom here \n\n");
	rotate_first_to_bottom(&lsta);
	i = 0;
	current = lsta;
	while (current)
	{
		printf("stack[%c]node[%d]: %d\n", current->stack_letter, i, current->number);
		current = current->next_number;
		i++;
	}
	return (0);
}
