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
# include <unistd.h>
# include <limits.h>

typedef struct s_elem
{
	int				number;
	int				index;
	int				position;
	int				is_above_center;
	int				cost;
	char			stack_letter;
	struct s_elem	*target_pos;
	struct s_elem	*next_number;
}					t_elem;

void	ft_lstadd_back(t_elem **lst, t_elem *new_node);
void	ft_lstadd_front(t_elem **lst, t_elem *new_node);
t_elem	*ft_lstlast(t_elem *lst);
t_elem	*ft_lstnew(int number, char letter);
int		ft_lstsize(t_elem *lst);

void	sx(t_elem **lst);
void	rx(t_elem **lst);
void	rrx(t_elem **lst);
void	px(t_elem **lst1, t_elem **lst2);
void	ss(t_elem **lst1, t_elem **lst2);
void	rr(t_elem **lst1, t_elem **lst2);
void	rrr(t_elem **lst1, t_elem **lst2);
void	perform_rr(t_elem **lst1, t_elem **lst2, t_elem *lower_cost);
void	perform_rrr(t_elem **lst1, t_elem **lst2, t_elem *lower_cost);
void	perform_final_ra_or_rra(t_elem **lst);

void	assign_index(t_elem *head, int current_position);
void	algo_case_1(t_elem **lst);
void	algo_case_2(t_elem **lst);
void	algo_case_3(t_elem **lst1, t_elem **lst2);
void	update_pos(t_elem **lst);
void	final_algo(t_elem **lst1, t_elem **lst2);
void	ft_move_b(t_elem **lst1, t_elem **lst2, t_elem *lower_cost_node);
void	ft_move_a(t_elem **lst1, t_elem **lst2, t_elem *lower_cost_node);
void	ft_finish_rotation(t_elem **lst, t_elem *lower_cost, char c);
void	move_elems_to_b(t_elem **lst1, t_elem **lst2);
void	cal_cost_a(t_elem **lst1, t_elem **lst2);
void	cal_cost_b(t_elem **lst1, t_elem **lst2);
int		ft_greater(int num1, int num2);

int		check_ordered(t_elem *lst);
int		input_duplicates_validator(t_elem **lst);
int		input_argc_validator(int argc, char **argv);
int		ft_count_items(const char *s, char c);
int		ft_atoi(const char *nptr);
int		input_item_validator(char **argv, int argc, int i);
int		input_validator(int argc, char **argv);
int		ft_nbr(char *nbr);
t_elem	*stack_builder(int argc, char **argv);

t_elem	*get_biggest_node(t_elem **lst);
t_elem	*get_smallest_node(t_elem **lst);
t_elem	*get_lower_cost_node(t_elem **lst);
t_elem	*ft_init_b(t_elem **lst1, t_elem **lst2);

char	**ft_split(char const *s, char c);
char	**input_argv_validator(int argc, char **argv);
char	**ft_free_split(char **result, int i);

#endif
