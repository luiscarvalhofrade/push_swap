/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:33:40 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/05 19:33:41 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BUILDER_H
# define STACK_BUILDER_H

# include <stdlib.h>

typedef struct s_list
{
	int				number;
	char			stack_letter;
	struct s_list	*next_number;
}					t_list;

t_list	*ft_lstnew(int content);

void	ft_lstadd_back(t_list **lst, t_list *new_node);

int		ft_isdigit(int c);

#endif
