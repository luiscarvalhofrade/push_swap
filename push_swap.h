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

typedef struct s_elem
{
	int				number;
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	char			stack_letter;
	struct s_elem	*next_number;
}					t_elem;

void	ft_lstadd_back(t_elem **lst, t_elem *new_node);
void	sx(t_elem **lst);
void	rx(t_elem **lst);
void	rrx(t_elem **lst);
void	ft_lstadd_front(t_elem **lst, t_elem *new_node);
void	px(t_elem **lst1, t_elem **lst2);
void	ss(t_elem **lst1, t_elem **lst2);
void	rr(t_elem **lst1, t_elem **lst2);
void	rrr(t_elem **lst1, t_elem **lst2);
void	movement_result(t_elem *lst1, t_elem *lst2);
void	resolution_algorithm(t_elem **lst1, t_elem **lst2);

int		input_duplicates_validator(t_elem **lst);
int		input_argc_validator(int argc, char **argv);
int		ft_count_items(const char *s, char c);
int		perform_sx(t_elem **lst);
int		perform_rx(t_elem **lst);
int		perform_rrx(t_elem **lst);
int		perform_pb(t_elem **lst1, t_elem **lst2);
int		perform_pa(t_elem **lst1, t_elem **lst2);
int		ft_atoi(const char *nptr);
int		input_item_validator(char **argv, int argc, int i);
int		input_validator(int argc, char **argv);

t_elem	*ft_lstlast(t_elem *lst);
t_elem	*stack_builder(int argc, char **argv);
t_elem	*ft_lstnew(int number, char letter);

int		ft_nbr(char *nbr);
int		ft_lstsize(t_elem *lst);
int		stack_ascending_checker(t_elem **lst);

char	**ft_split(char const *s, char c);
char	**input_argv_validator(int argc, char **argv);

#endif
