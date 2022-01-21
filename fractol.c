/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/21 11:11:26 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plot_julia(t_Window *fr)
{
	unsigned int	px;
	unsigned int	py;
	unsigned int	n;
	unsigned int	is_inside;
	double			c_re;
	double			z_re;
	double			z_re2;
	double			c_im;
	double			z_im;
	double			z_im2;

	px = 0;
	py = 0;
	n = 0;
	while (py < fr->size_y)
	{
		c_im = fr->imax - py * (fr->imax - fr->imin) / (fr->size_y - 1); // im_factor
		while (px < fr->size_x)
		{
			c_re = fr->rmin + px * (fr->rmax - fr->rmin) / (fr->size_x - 1); //re_factor
			z_re = c_re + fr->k_re;
			z_im = c_im + fr->k_im;
			is_inside = 1;
			while (n < fr->max_iter)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				if (z_re2 + z_im2 > 4)
				{
					is_inside = 0;
					break ;
				}
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				n++;
			}
			if (is_inside == 1)
				my_mlx_pixel_put(fr, px, py, 0x00000000);
			else
				my_mlx_pixel_put(fr, px, py, color_scale(n, fr->color_shift));
			n = 0;
			px++;
		}
		px = 0;
		py++;
	}
}

/*
 * sets Julia parameter K = 0.353 + 0.288i if no user parameters supplied
 */
void	init_julia(int argc, char **argv, t_Window *fr)
{
	fr->fractal_set = "Julia";
	if (argc > 2)
		fr->k_re = atof(argv[2]);
	else
		fr->k_re = 0.153;
	if (argc > 3)
		fr->k_im = atof(argv[3]);
	else
		fr->k_im = 0.288;
	if (argc > 4)
		fr->color_shift = atoi(argv[4]);
	ft_printf("Julia set with K = %f + %fi\n", fr->k_re, fr->k_im);
}

void	init_mandelbrot(int argc, char **argv, t_Window *fr)
{
	fr->fractal_set = "Mandelbrot";
	fr->k_re = 0;
	fr->k_im = 0;
	if (argc > 2)
		fr->color_shift = atoi(argv[2]);
	ft_printf("Mandelbrot set\n");
}

/*
 * handle Mandelbrot and Julia fractal sets
 */
int	main(int argc, char **argv)
{
	t_Window	fr;

	fr.color_shift = 0;
	if (argc < 2)
	{
		ft_printf("ERROR: wrong args! Call as:\n");
		ft_printf("  fractol <fractal set> <params>\n");
		return (1);
	}
	if (ft_strncmp(argv[1], "Julia", 5) == 0 || ft_strncmp(argv[1], "J", 1) == 0)
		init_julia(argc, argv, &fr);
	else if (ft_strncmp(argv[1], "M", 1) == 0 || ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		init_mandelbrot(argc, argv, &fr);
	else
	{
		ft_printf("ERROR: fractal unknown! Call as:\n");
		ft_printf("  fractol <(Julia|Mandelbrot)> (<params>) <color shift>\n");
		return (1);
	}
	init_window(&fr);
	plot_image(&fr);
	mlx_key_hook(fr.window, handle_keypress, &fr);
	mlx_mouse_hook(fr.window, mouse_event, &fr);
	mlx_loop(fr.display);
	return (0);
}
