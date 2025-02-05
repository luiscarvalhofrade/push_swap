/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:56:44 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/05 18:57:34 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	final_algo(&lsta, &lstb);
	free_lst(lsta);
	free_lst(lstb);
	return (0);
}
