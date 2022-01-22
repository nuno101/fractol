/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_driver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/22 13:21:51 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * bpp - bits per pixel
 * ll - line length
 */
void	my_mlx_pixel_put(t_Window *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->ll + x * (fr->bpp / 8));
	*(unsigned int *)dst = color;
}

/*
 * create new image in memory
 * replace image in window 
 */
void	plot_image(t_Window *fr)
{
	ft_printf("Plot %s. k_re\n", fr->fractal_set);
	plot_fractal(fr);
	mlx_put_image_to_window(fr->display, fr->window, fr->image, 0, 0);
}

/*
 * initialise minilibx and image dimensions
 */
void	init_window(t_Window *f)
{
	f->size_x = 1024;
	f->size_y = 768;
	f->color_shift = 0;
	f->display = mlx_init();
	f->window = mlx_new_window(f->display, f->size_x, f->size_y, "Fract-ol");
	f->image = mlx_new_image(f->display, f->size_x, f->size_y);
	f->addr = mlx_get_data_addr(f->image, &(f->bpp), &(f->ll), &(f->endian));
	f->max_iter = 30;
	reset_zoom(f);
}
