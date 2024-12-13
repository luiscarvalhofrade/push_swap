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
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				number;
	char			stack_letter;
	struct s_list	*next_number;
}					t_list;

void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	sx(t_list **lst);
void	rx(t_list **lst);
void	rrx(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	px(t_list **lst1, t_list **lst2);
void	ss(t_list **lst1, t_list **lst2);
void	rr(t_list **lst1, t_list **lst2);
void	rrr(t_list **lst1, t_list **lst2);
void	movement_result(t_list *lst1, t_list *lst2);
void	resolution_algorithm(t_list **lst1, t_list **lst2);

int		duplicates_validator(t_list **lst);
int		ft_count_words(const char *s, char c);
int		perform_sx(t_list **lst);
int		perform_rx(t_list **lst);
int		perform_rrx(t_list **lst);
int		perform_pb(t_list **lst1, t_list **lst2);
int		perform_pa(t_list **lst1, t_list **lst2);

t_list	*ft_lstlast(t_list *lst);
t_list	*stack_builder(int argc, char **argv);
t_list	*ft_lstnew(int number, char letter);

int		ft_isdigit(int c);
int		ft_lstsize(t_list *lst);
int		stack_ascending_checker(t_list **lst);

char	**ft_split(char const *s, char c);

#endif
