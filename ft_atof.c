/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:55:35 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/10 16:17:07 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atof.h"

static int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || \
			c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

double	ft_atof(const char *str)
{
	int			i;
	int			sign;
	long double	nr;
	long double	decimals;

	i = 0;
	sign = 1;
	nr = 0;
	decimals = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	if (!ft_isdigit(*(str + i)))
		return (0);
	while (ft_isdigit(*(str + i)) || *(str + i) == '.')
	{
		if (*(str + i) == '.')
			decimals = 1;
		else
		{
			nr = nr * 10 + (*(str + i) - '0');
			decimals = decimals * 10;
		}
		i++;
	}
	if (decimals == 0)
		decimals = 1;
	return ((double)(sign * nr / decimals));
}
