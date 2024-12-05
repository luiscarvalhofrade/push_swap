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

typedef struct s_list
{
	int 			number;
	char			stack_letter;
	struct s_list 	*next_number;
} 					t_list;

#endif
