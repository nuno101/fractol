/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/10 17:29:08 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_fractal(t_Window *fr, t_Coordinates *xy)
{
	double			z_re;
	double			z_re2;
	double			z_im;
	double			z_im2;
	unsigned int	n;

	n = 0;
	z_re = xy->c_re;
	z_im = xy->c_im;
	while (n < fr->max_iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			break ;
		if (ft_strncmp(fr->fractal_set, "Mandelbrot", 10) == 0)
		{
			z_im = 2 * z_re * z_im + xy->c_im;
			z_re = z_re2 - z_im2 + xy->c_re;
		}
		else
		{
			z_im = 2 * z_re * z_im + fr->k_im;
			z_re = z_re2 - z_im2 + fr->k_re;
		}
		n++;
	}
	if (z_re2 + z_im2 > 4)
		my_mlx_pixel_put(fr, xy->px, xy->py, clr_scale(fr, n));
	else
		my_mlx_pixel_put(fr, xy->px, xy->py, 0x00000000);
}

/*
 * walk through each pixel in the xx and yy axis
 * calculate real/imaginary coordinates for each pixel
 * call the fractal function
 */
void	plot_fractal(t_Window *f)
{
	t_Coordinates	xy;

	xy.px = 0;
	xy.py = 0;
	while (xy.py < f->size_y)
	{
		xy.c_im = f->imax - xy.py * (f->imax - f->imin) / (f->size_y - 1);
		while (xy.px < f->size_x)
		{
			xy.c_re = f->rmin + xy.px * (f->rmax - f->rmin) / (f->size_x - 1);
			calculate_fractal(f, &xy);
			xy.px++;
		}
		xy.px = 0;
		xy.py++;
	}
}

/*
 * sets Julia parameter K = 0.353 + 0.288i if no user parameters supplied
 */
void	init_julia(int argc, char **argv, t_Window *fr)
{
	fr->fractal_set = "Julia";
	if (argc > 2)
		fr->k_re = ft_atof(argv[2]);
	else
		fr->k_re = -0.835;
	if (argc > 3)
		fr->k_im = ft_atof(argv[3]);
	else
		fr->k_im = -0.2321;
	if (argc > 4)
		fr->clr_shift = ft_atoi(argv[4]);
	ft_printf("Julia set\n");
}

void	init_mandelbrot(int argc, char **argv, t_Window *fr)
{
	fr->fractal_set = "Mandelbrot";
	fr->k_re = 0;
	fr->k_im = 0;
	if (argc > 2)
		fr->clr_shift = ft_atoi(argv[2]);
	ft_printf("Mandelbrot set\n");
}

/*
 * handle Mandelbrot and Julia fractal sets
 */
int	main(int argc, char **argv)
{
	t_Window	fr;

	if (argc < 2)
	{
		ft_printf("ERROR! Call as: fractol <fractal set> <params>\n");
		return (1);
	}
	if (ft_strncmp(argv[1], "Julia", 5) == 0
		|| ft_strncmp(argv[1], "J", 1) == 0)
		init_julia(argc, argv, &fr);
	else if (ft_strncmp(argv[1], "M", 1) == 0
		|| ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
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
