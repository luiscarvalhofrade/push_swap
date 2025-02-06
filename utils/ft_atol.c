/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:14:49 by luide-ca          #+#    #+#             */
/*   Updated: 2025/02/06 15:36:03 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(char *str)
{
	long	nbr;
	long	minus;
	long	i;

	i = 0;
	nbr = 0;
	minus = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * minus);
}
