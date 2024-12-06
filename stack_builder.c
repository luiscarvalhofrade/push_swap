/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:44:14 by luide-ca          #+#    #+#             */
/*   Updated: 2024/12/05 19:44:16 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_builder.h"

int	*convert_argv(int argc, char **argv)
{
	int	k;
	int	*ints_arr;

	argc = argc - 1;
	ints_arr = (int *)malloc((argc) * sizeof(int));
	if (!ints_arr)
		return (0);
	while (argc > 0)
	{
		k = 0;
		while (argv[argc][k] != '\0')
		{
			if (ft_isdigit(argv[argc][k]) != 1)
			{
				if (ints_arr)
					free(ints_arr);
				return (0);
			}
			k++;
		}
		ints_arr[argc - 1] = atoi(argv[argc]);
		argc--;
	}
	return (ints_arr);
}

t_list	stack_builder(int argc, char **argv)
{
	int	*ints_arr;

	ints_arr = convert_argv(argc, argv);
	if (!ints_arr)
		return (0);
	while ()
	
}
