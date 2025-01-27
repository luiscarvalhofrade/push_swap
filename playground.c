#include "push_swap.h"

t_elem	*pick_smaller_cost(t_elem **lst)
{
	t_elem	*current;
	t_elem	*min_elem;
	int		min_cost;

	current = *lst;
	min_elem = NULL;
	min_cost = INT_MAX;
	while (current)
	{
		if (current->total_cost < min_cost)
		{
			min_cost = current->total_cost;
			min_elem = current;
		}
		current = current->next_number;
	}
	return (min_elem);
}

void	perform_rx_or_rrx(int cost, t_elem **lst)
{
	if (cost < 0)
	{
		while (cost < 0)
		{
			rrx(lst);
			cost++;
		}
	}
	else
	{
		while (cost > 0)
		{
			rx(lst);
			cost--;
		}
	}
}

void	solve_elem(t_elem *small_cost, t_elem **lst1, t_elem **lst2)
{
	int	cost_a;
	int	cost_b;

	cost_a = small_cost->cost_a;
	cost_b = small_cost->cost_b;
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(lst1, lst2);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		rr(lst1, lst2);
		cost_a--;
		cost_b--;
	}
	perform_rx_or_rrx(cost_b, lst2);
	perform_rx_or_rrx(cost_a, lst1);
	px(lst2, lst1);
}

void	define_target_pos_stack_a(t_elem **lst1, t_elem **lst2)
{  
	t_elem	*current1;
	t_elem	*current2;
	int		size1;

	current1 = *lst1;
	size1 = ft_lstsize(*lst1);
	while (size1 > 3)
	{
		current2 = *lst2;
		current1->target_pos = 0;
		while (current2)
		{
			if (current1->index > current2->index)
				current1->target_pos = current2->position;
			current2 = current2->next_number;
		}
		size1--;
		current1 = current1->next_number;
	}
}

void	define_target_pos_stack_b(t_elem **lst1, t_elem **lst2)
{  
	t_elem	*current1;
	t_elem	*current2;

	current2 = *lst2;
	while (current2)
	{
		current1 = *lst1;
		current2->target_pos = 0;
		while (current1)
		{
			if (current2->index > current1->index)
				current2->target_pos = current1->position + 1;
			current1 = current1->next_number;
		}
		current2 = current2->next_number;
	}
}
void	algo_case_3(t_elem **lst1, t_elem **lst2)
{
	int		lst_size1;
	int		lst_size2;
	t_elem	*small_cost;

	lst_size1 = ft_lstsize(*lst1);
	while (lst_size1 > 3)
	{
		define_target_pos_stack_a(lst1, lst2);
		cost_cal(lst2, lst1);
		small_cost = pick_smaller_cost(lst2);
		solve_elem(small_cost, lst1, lst2);
		lst_size1--;
	}
	algo_case_2(lst1);
	lst_size2 = ft_lstsize(*lst2);
	while (lst_size2 > 0)
	{
		define_target_pos_stack_b(lst1, lst2);
		cost_cal(lst1, lst2);
		small_cost = pick_smaller_cost(lst2);
		solve_elem(small_cost, lst1, lst2);
		lst_size2 = ft_lstsize(*lst2);
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
	algo(&lsta, &lstb);
	return (0);
}
