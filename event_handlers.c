/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:44:13 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/21 09:41:12 by nlouro           ###   ########.fr       */
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
	fr->rmax = 1.0;
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

/*
 * esc - exit
 * m and j - mandelbrot and julia sets
 * z and x - zoom in and out
 */
int handle_keypress(int keycode, t_Window *fr)
{
	ft_printf("key pressed %i", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 46)
	{
		fr->fractal_set = "Mandelbrot";
		reset_zoom(fr);
		fr->k_re = 0;
		fr->k_im = 0;
	}
	else if (keycode == 38)
	{
		fr->fractal_set = "Julia";
		reset_zoom(fr);
		fr->k_re = 0.153;
		fr->k_im = 0.288;
	}
	else if (keycode == 6)
		zoom(fr, 0.8);
	else if (keycode == 7)
		zoom(fr, 1.2);
	else if (keycode == 123)
		shift_raxis(fr, -0.05);
	else if (keycode == 124)
		shift_raxis(fr, 0.05);
	else if (keycode == 125)
		shift_iaxis(fr, -0.05);
	else if (keycode == 126)
		shift_iaxis(fr, 0.05);
	plot_image(fr);
	return (0);
}

int mouse_event(int button, int x, int y, void *fr)
{
	ft_printf("x: %i y: %i button: %i\n", x, y, button);
	if (button == 4)
		zoom(fr, 0.97);
	else if (button == 5)
		zoom(fr, 1.03);
	else if (button == 6)
		shift_raxis(fr, -0.1);
	else if (button == 7)
		shift_raxis(fr, 0.1);
	plot_image(fr);
	return (0);
}
