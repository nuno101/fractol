/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:44:13 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/21 08:08:06 by nlouro           ###   ########.fr       */
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
		plot_image(fr);
	}
	else if (keycode == 38)
	{
		fr->fractal_set = "Julia";
		reset_zoom(fr);
		fr->k_re = 0.153;
		fr->k_im = 0.288;
		plot_image(fr);
	}
	else if (keycode == 6)
	{
		zoom(fr, 0.8);
		plot_image(fr);
	}
	else if (keycode == 7)
	{
		zoom(fr, 1.2);
		plot_image(fr);
	}
	return (0);
}

int mouse_event(int button, int x, int y, void *param)
{
	void	*p;

	p = param;
	ft_printf("x: %i y: %i button: %i\n", x, y, button);
	return (0);
}
