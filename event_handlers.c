/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:44:13 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/04 11:54:48 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	restart_mandelbrot(t_Window *fr)
{
	fr->fractal_set = "Mandelbrot";
	reset_zoom(fr);
	fr->k_re = 0;
	fr->k_im = 0;
}

void	restart_julia(t_Window *fr)
{
	fr->fractal_set = "Julia";
	reset_zoom(fr);
	fr->k_re = -0.835;
	fr->k_im = -0.2321;
}

/*
 * esc and q - exit
 * m and j - mandelbrot and julia sets
 * z and x - zoom in and out
 */
int	handle_keypress(int keycode, t_Window *fr)
{
	ft_printf("key pressed %i", keycode);
	if (keycode == 53 || keycode == 12)
		exit(0);
	else if (keycode == 46)
		restart_mandelbrot(fr);
	else if (keycode == 38)
		restart_julia(fr);
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

int	mouse_event(int button, int x, int y, void *fr)
{
	if (button == 4)
		zoom_from(fr, x, y, 1.03);
	else if (button == 5)
		zoom_from(fr, x, y, 0.97);
	plot_image(fr);
	return (0);
}
