/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/20 21:54:17 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_Window *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
 * walk over each pixel
 * convert pixel position to (x,y) and calculate z
 * for Mandelbrot set k_re = k_im = 0
 */
void	plot_julia(t_Window *fr)
{
	unsigned	int	px = 0;
	unsigned	int	py = 0;
	unsigned	int	n = 0;
	unsigned	int	max_iter = 30;
	double	rmin = -2.0;
	double	rmax = 1.0;
	double	imin = -1.2;
	double	imax = 1.2;
	double	re_factor = (rmax - rmin) / (fr->size_x - 1);
	double	im_factor = (imax - imin) / (fr->size_y - 1);
	unsigned	int is_inside;
	double	c_re;
	double	z_re;
	double	z_re2;
	double	c_im;
	double	z_im;
	double	z_im2;

	while (py < fr->size_y)
	{
		c_im = imax - py * im_factor;
		while (px < fr->size_x)
		{
			c_re = rmin + px * re_factor;
			z_re = c_re + fr->k_re;
			z_im = c_im + fr->k_im;
			is_inside = 1;
			while(n < max_iter)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				//ft_printf("px: %i py: %i n: %i z_re2: %f z_im2: %f \n", px, py, n, z_re2, z_im2);
				if (z_re2 + z_im2 > 4)
				{
					is_inside = 0;
					break;
				}
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				n++;
			}
			if (is_inside == 1)
				my_mlx_pixel_put(fr, px, py, 0x00000000);
			else
				my_mlx_pixel_put(fr, px, py, color_scale(n) + fr->color_shift);
			n = 0;
			px++;
		}
		px = 0;
		py++;
	}

}

/*
 * call funtion to create new image in memory
 * replace image in window 
 */
void	plot_image(t_Window *fr)
{
	ft_printf("Plot %s. k_re\n", fr->fractal_set);
	plot_julia(fr);
	mlx_put_image_to_window(fr->display, fr->window, fr->image, 0, 0);
}

/*
 * handle esc, m and j keys
 */
int	handle_key(int keycode, t_Window *fr)
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

int	mouse_event(int button, int x, int y, void *param)
{
	void	*p;

	p = param;
	ft_printf("x: %i y: %i button: %i\n", x, y, button);
	return (0);
}

void	init_window(t_Window *fr)
{
	fr->size_x = 1024;
	fr->size_y = 768;
	fr->display= mlx_init();
	fr->window = mlx_new_window(fr->display, fr->size_x, fr->size_y, "Fract-ol");
	fr->image = mlx_new_image(fr->display, fr->size_x, fr->size_y);
	fr->addr = mlx_get_data_addr(fr->image, &(fr->bits_per_pixel), &(fr->line_length), &(fr->endian));
/*
	ft_printf("bpp: %i\n", fr->bits_per_pixel);
	ft_printf("line_length: %i\n", fr->line_length);
	ft_printf("endian: %i\n", fr->endian);
*/
}

/*
 * handles Mandelbrot and Julia fractal sets
 * sets Julia parameter K = 0.353 + 0.288i if no user parameters supplied
 *
 */
int	main(int argc, char **argv)
{
	t_Window	fr;

	fr.color_shift = 0;
	if (argc < 2)
	{
		ft_printf("ERROR: wrong args. Call as:\n fractol <fractal set> <params>\n");
		return (1);
	}
	if (ft_strncmp(argv[1], "Julia", 5) == 0 || ft_strncmp(argv[1], "J", 1) == 0)
	{
		fr.fractal_set = "Julia";
		if (argc > 2)
			fr.k_re = atof(argv[2]);
		else
			fr.k_re = 0.153;
		if (argc > 3)
			fr.k_im = atof(argv[3]);
		else
			fr.k_im = 0.288;
		if (argc > 4)
			fr.color_shift = atoi(argv[4]);
		ft_printf("Julia set with K = %f + %fi\n", fr.k_re, fr.k_im);
	}
	else if (ft_strncmp(argv[1], "M", 1) == 0 || ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		fr.fractal_set = "Mandelbrot";
		ft_printf("Mandelbrot set\n");
		fr.k_re = 0;
		fr.k_im = 0;
		if (argc > 2)
			fr.color_shift = atoi(argv[2]);
	}
	else
	{
		ft_printf("ERROR: fractal name unknown. Call as:\n fractol <(Julia|Mandelbrot)> (<params>) <color shift>\n");
		return (1);
	}
	init_window(&fr);
	plot_image(&fr);
	mlx_key_hook(fr.window, handle_key, &fr);
	mlx_mouse_hook(fr.window, mouse_event, 0);
	mlx_loop(fr.display);
	return (0);
}
