/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/07 17:23:56 by nlouro           ###   ########.fr       */
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
 * walk over the pixels
 * convert pixel position to (x,y) and calculate z
 */
void	plot_mandelbrot(t_Window *fr)
{
	int	px;
	int	py;
	float	xmin;
	float	xmax;
	float	ymin;
	float	ymax;
	double	z;
	float	zmax;
	float	x;
	float	y;
	int	n;
	int	iter; //max iterations of z calculation
	int	color;
	int	color2;

	px = 0;
	py = fr->size_y;
	xmin = -1.5;
	xmax = 	0.5;
	ymin = -1.0;
	ymax = 	1.0;
	n = 0;
	iter = 200;
	zmax = 2.0;
	z = 0.0;

	color = 0x00FFFFFF;
	color2 = 0x00AABBFF;

	while (py >= 0)
	{
		y = ymax - py * (ymax - ymin) / fr->size_y;
		while (px <= fr->size_x)
		{
			//printf("px: %i py: %i\n", px, py);
			x = xmin + px * (xmax - xmin) / fr->size_x;
			while (n <= iter && z < zmax)
			{
				z = z*z + sqrt(x * x + y * y); 
				//printf("px: %i py: %i n: %i x: %f y: %f z: %f\n", px, py, n, x, y, z);
				if (z > zmax)
					break;
				if (n == iter)
					my_mlx_pixel_put(fr, px, py, color);
				n++;
			}
			n = 0;
			z = 0;
			px++;
		}
		px = 0;
		py--;
	}
	// plot (0,0)
	my_mlx_pixel_put(fr, fr->size_x / 2, fr->size_y / 2, 0x00FFFFBB);
}

void	pplot_mandelbrot(t_Window *fr)
{
	int	x;
	int	y;
	int	color;

	x = 5;
	y = 5;
	color = 0x00FFFFFF;

	while (x < fr->size_x - 5)
	{
		while (y < fr->size_y - 5)
		{
			my_mlx_pixel_put(fr, x, y, color);
			y++;
		}
		y = 5;
		x++;
	}
}


int	handle_key(int keycode, void *param)
{
	void	*p;

	p = param;
	//printf("key pressed %i", keycode);
	if (keycode == 53)
		exit(0);
	else
		return (0);
}

int	mouse_event(int button, int x, int y, void *param)
{
	void	*p;

	p = param;
	printf("x: %i y: %i button: %i\n", x, y, button);
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
	printf("bpp: %i\n", fr->bits_per_pixel);
	printf("line_length: %i\n", fr->line_length);
	printf("endian: %i\n", fr->endian);
}

int	main(int argc, char **argv)
{
	t_Window	fr;

	if (argc < 2)
	{
		printf("ERROR: wrong args. Call as:\n fractol <fractal set> <params>\n");
		return (1);
	}
	if (strcmp(argv[1], "Julia") == 0)
		printf("Julia set");
	else if (strcmp(argv[1], "Mandelbrot") == 0)
		printf("Mandelbrot set\n");
	fr.set = argv[1];
	init_window(&fr);
	// create new image in memory
	pplot_mandelbrot(&fr);
	// replace image shown
	mlx_put_image_to_window(fr.display, fr.window, fr.image, 0, 0);
	mlx_key_hook(fr.window, handle_key, &fr);
	mlx_mouse_hook(fr.window, mouse_event, 0);
	mlx_loop(fr.display);
	return (0);
}
