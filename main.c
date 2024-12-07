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

void	movement_result(t_list *lsta, t_list *lstb)
{
	int		i;
	int		j;
	t_list	*current;
	t_list	*currentb;

	current = lsta;
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
	currentb = lstb;
	while (currentb)
	{
		printf("[%c]no[%d]:%d\n", currentb->stack_letter, j, currentb->number);
		currentb = currentb->next_number;
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;
	int		result;

	lsta = NULL;
	lstb = NULL;
	if (argc < 3)
		return (printf("Error\n"));
	lsta = stack_builder(argc, argv);
	if (!lsta || lsta == 0)
		return (printf("Error\n"));
	movement_result(lsta, lstb);
	result = stack_ascending_checker(&lsta);
	push_to_other_stack(&lsta, &lstb);
	movement_result(lsta, lstb);
	result = stack_ascending_checker(&lsta);
	printf("\nresult: %d\n", result);
	return (0);
}
