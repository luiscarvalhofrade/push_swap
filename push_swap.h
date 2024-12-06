/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:33:40 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/05 19:33:41 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_list
{
	int				number;
	char			stack_letter;
	struct s_list	*next_number;
}					t_list;

t_list	*ft_lstnew(int number, char letter);

void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	swap_positions_top(t_list **lst);
void	rotate_first_to_bottom(t_list **lst);
void	rotate_last_to_top(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	push_to_other_stack(t_list **lst1, t_list **lst2);

t_list	*ft_lstlast(t_list *lst);

int	ft_isdigit(int c);
int	ft_lstsize(t_list *lst);

#endif
