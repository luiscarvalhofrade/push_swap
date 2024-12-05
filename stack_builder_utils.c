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

#include "stack_builder.h"

t_list	*ft_find_last_node(t_list *list)
{
	if (!list)
		return (0);
	while (list->next_number)
		list = list->next_number;
	return (list);
}
