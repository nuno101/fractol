/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:44:13 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/21 07:47:26 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * handle esc, m and j keys
 */
int handle_keypress(int keycode, t_Window *fr)
{
	ft_printf("key pressed %i", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 46) // m key
	{
		fr->fractal_set = "Mandelbrot";
		fr->k_re = 0;
		fr->k_im = 0;
		plot_image(fr);
	}
	else if (keycode == 38) // m key
	{
		fr->fractal_set = "Julia";
		fr->k_re = 0.153;
		fr->k_im = 0.288;
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
