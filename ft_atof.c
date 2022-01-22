/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:55:35 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/22 11:54:13 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atof.h"
#include <stdio.h>

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
	int		i;
	int		sign;
	long double	nr;
	long double	decimals;

	i = 0;
	sign = 1;
	nr = 0;
	decimals = 1;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	if (!ft_isdigit(*(str + i)))
		return (0);
	while (ft_isdigit(*(str + i)))
	{
		nr = nr * 10 + (*(str + i) - '0');
		//if (sign == 1 && nr > 2147483647)
		//	return (-1);
		//if (sign == -1 && nr > 2147483648)
		//	return (0);
		i++;
	}
	if (*(str + i) == '.')
		i++;
	while (ft_isdigit(*(str + i)))
	{
		decimals = decimals * 10;
		nr = nr * 10 + (*(str + i) - '0');
		i++;
	}
	return ((double)(sign * nr / decimals));
}
