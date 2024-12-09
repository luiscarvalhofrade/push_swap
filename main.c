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

void	movement_result(t_list *lst1, t_list *lst2)
{
	int		i;
	int		j;
	t_list	*current;
	t_list	*currentb;

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

void	free_lst(t_list *head)
{
    t_list	*temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next_number;
        free(temp);
    }
}

int	main(int argc, char **argv)
{
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	if (argc < 3)
		return (printf("Error\n"));
	lsta = stack_builder(argc, argv);
	if (!lsta || lsta == 0)
		return (printf("Error\n"));
	resolution_algorithm(&lsta, &lstb);
	free_lst(lsta);
	free_lst(lstb);
	return (0);
}
