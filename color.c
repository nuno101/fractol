/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:40:42 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/15 11:44:45 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//unsigned    int color_scale(unsigned int n);

unsigned    int rgb2int(int red, int green, int blue)
{
    return (256 * 256 * red + 256 * green + blue);
}
/*
 * colors from https://stackoverflow.com/questions/16500656/which-color-gradient-is-used-to-color-mandelbrot-in-wikipedia
 */
unsigned    int color_scale(unsigned int n)
{
    static unsigned int **scale;

    *scale[0] = rgb2int(66, 30, 15);
    *scale[1] = rgb2int(25, 7, 26);
    *scale[2] = rgb2int(9, 1, 47);
    *scale[3] = rgb2int(4, 4, 73);
    *scale[4] = rgb2int(0, 7, 100);
    *scale[5] = rgb2int(12, 44, 138);
    *scale[6] = rgb2int(24, 82, 177);
    *scale[7] = rgb2int(57, 125, 209);
    *scale[8] = rgb2int(134, 181, 229);
    *scale[9] = rgb2int(211, 236, 248);
    *scale[10] = rgb2int(241, 233, 191);
    *scale[11] = rgb2int(248, 201, 95);
    *scale[12] = rgb2int(255, 170, 0);
    *scale[13] = rgb2int(204, 128, 0);
    *scale[14] = rgb2int(153, 87, 0);
    *scale[15] = rgb2int(106, 52, 3);

    return (*scale[n]);
}
