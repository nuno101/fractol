/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:00:34 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/20 21:55:18 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strncmp.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((*s1 != '\0' && *s2 != '\0') && i + 1 < n && *s1 == *s2)
	{
		i++;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
