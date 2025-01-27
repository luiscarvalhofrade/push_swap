/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:29:44 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/27 16:17:51 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void    step_2(t_elem **lst)
{
	t_elem	*current;
	t_elem	*next;

	current = *lst;
	next = current->next_number;
	if (current->index < next->index)
		sx(lst);
	return ;
}

void    step_3(t_elem **lst1, t_elem **lst2)
{
    t_elem  *min_cost;

    update_pos_n_tar_pos(lst1, lst2);
    cost_cal(lst1, lst2);
    min_cost = pick_min_cost(lst1);
    make_min_cost(lst1, lst2);
}

void	algo_case_3(t_elem **lst1, t_elem **lst2)
{  
    int i;

    i = 2;
	while (i > 0)
    {
        px(lst1, lst2);
        i--;
    }
    step_2(lst2);
    step_3(lst1, lst2);
    algo_case_2(lst1);
    step_3(lst2, lst1);
}