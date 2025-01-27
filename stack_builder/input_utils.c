/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:15:41 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/15 16:47:34 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**input_argv_validator(int argc, char **argv)
{
	char	**final_argv;

	if (argc == 2)
		final_argv = ft_split(argv[1], ' ');
	else
		final_argv = argv;
	return (final_argv);
}

int	input_argc_validator(int argc, char **argv)
{
	int	final_argc;

	if (argc == 2)
		final_argc = ft_count_items(argv[1], ' ');
	else
		final_argc = argc;
	return (final_argc);
}
