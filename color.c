/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:40:42 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/10 17:24:55 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * RGB to integer converter
 */
unsigned	int	rgb2int(int red, int green, int blue)
{
	return (256 * 256 * red + 256 * green + blue);
}

unsigned	int	clr_scale(t_Window *fr, unsigned int n)
{
	if (n > 15)
		n = 15;
	return (*(fr->scale[n]) + (double)(fr->clr_shift || 0));
}

/*
 * hard coded color scale calculated once from a list of RGB colors
 * color scale from https://bit.ly/3rGNBEd
 */
void	set_clr_scale(t_Window *fr)
{
	int	i;

	i = -1;
	while (i++ < 16)
		fr->scale[i] = (unsigned int *) calloc(1, sizeof(int));
	*(fr->scale[0]) = rgb2int(66, 30, 15);
	*(fr->scale[1]) = rgb2int(25, 7, 26);
	*(fr->scale[2]) = rgb2int(9, 1, 47);
	*(fr->scale[3]) = rgb2int(4, 4, 73);
	*(fr->scale[4]) = rgb2int(0, 7, 100);
	*(fr->scale[5]) = rgb2int(12, 44, 138);
	*(fr->scale[6]) = rgb2int(24, 82, 177);
	*(fr->scale[7]) = rgb2int(57, 125, 209);
	*(fr->scale[8]) = rgb2int(134, 181, 229);
	*(fr->scale[9]) = rgb2int(211, 236, 248);
	*(fr->scale[10]) = rgb2int(241, 233, 191);
	*(fr->scale[11]) = rgb2int(248, 201, 95);
	*(fr->scale[12]) = rgb2int(255, 170, 0);
	*(fr->scale[13]) = rgb2int(204, 128, 0);
	*(fr->scale[14]) = rgb2int(153, 87, 0);
	*(fr->scale[15]) = rgb2int(106, 52, 3);
}
