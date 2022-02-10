/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:44:13 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/10 16:10:53 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_Window *fr, double z)
{
	fr->rmin = z * fr->rmin;
	fr->rmax = z * fr->rmax;
	fr->imin = z * fr->imin;
	fr->imax = z * fr->imax;
}

void	reset_zoom(t_Window *fr)
{
	fr->rmin = -2.0;
	if (ft_strncmp(fr->fractal_set, "Mandelbrot", 10) == 0)
		fr->rmax = 1.0;
	else
		fr->rmax = 2.0;
	fr->imin = -1.2;
	fr->imax = 1.2;
}

void	shift_raxis(t_Window *fr, double s)
{
	fr->rmin = s + fr->rmin;
	fr->rmax = s + fr->rmax;
}

void	shift_iaxis(t_Window *fr, double s)
{
	fr->imin = s + fr->imin;
	fr->imax = s + fr->imax;
}

void	zoom_from(t_Window *fr, double px, double py, double z)
{
	double	trx;
	double	try;

	trx = (px - fr->size_x / 2) * (fr->rmax - fr->rmin) / fr->size_x;
	try = (py - fr->size_y / 2) * (fr->imax - fr->imin) / fr->size_y;
	shift_raxis(fr, 0.2 * trx);
	shift_iaxis(fr, -0.2 * try);
	zoom(fr, z);
}
