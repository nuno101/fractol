/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/14 16:03:53 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned	int	color_scale(unsigned int n);

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
	int	color = 0x00FFFFFF;
	int	red = 0x00FF0000;

	while (py < fr->size_y)
	{
		c_im = imax - py * im_factor;
		while (px < fr->size_x)
		{
			c_re = rmin + px * re_factor;
			z_re = c_re;
			z_im = c_im;
			is_inside = 1;
			while(n < max_iter)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				//printf("px: %i py: %i n: %i z_re2: %f z_im2: %f \n", px, py, n, z_re2, z_im2);
				if ((z_re2 + z_im2) > 4)
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
			{
			if (n == 0)
				my_mlx_pixel_put(fr, px, py, color);
			if (n == 1)
				my_mlx_pixel_put(fr, px, py, red);
			if (n == 2)
				my_mlx_pixel_put(fr, px, py, 0x000000FF);
			if (n >= 3)
				my_mlx_pixel_put(fr, px, py, 0x0000FFFF);
			if (n >= 4)
				my_mlx_pixel_put(fr, px, py, (n + 30) * 256 * 256 + 28 * 256 + 128);
				//my_mlx_pixel_put(fr, px, py, color_scale(n));
			}
			n = 0;
			px++;
		}
		px = 0;
		py++;
	}

}

void	plot_white(t_Window *fr)
{
	unsigned int	x;
	unsigned int	y;
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

unsigned	int rgb2int(unsigned int red, unsigned int green, unsigned int blue)
{
	return (256 * 256 * red + 256 * green + blue);
}

unsigned	int	color_scale(unsigned int n)
{
	static unsigned int **scale;

	*scale[0] = rgb2int(66, 30, 15);
    *scale[1] = rgb2int(25, 7, 26);
    *scale[2] = rgb2int(9, 1, 47);
    *scale[3] = rgb2int(4, 4, 73);
    *scale[4] = rgb2int(0, 7, 100);
    *scale[5] = rgb2int(12, 44, 138);
    *scale[6] = rgb2int(24, 82, 177);
    *scale[7] = rgb2int(57, 125, 209);
    *scale[8] = rgb2int(134, 181, 229);
    *scale[9] = rgb2int(211, 236, 248);
    *scale[10] = rgb2int(241, 233, 191);
    *scale[11] = rgb2int(248, 201, 95);
    *scale[12] = rgb2int(255, 170, 0);
    *scale[13] = rgb2int(204, 128, 0);
    *scale[14] = rgb2int(153, 87, 0);
    *scale[15] = rgb2int(106, 52, 3);

	return (*scale[n]);
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
	else if (strcmp(argv[1], "M") == 0 || strcmp(argv[1], "Mandelbrot") == 0)
		printf("Mandelbrot set\n");
	//printf("cs: %i\n", color_scale(0));
	printf("cs: %i\n", rgb2int(106, 52, 3));
	fr.set = argv[1];
	init_window(&fr);
	//init_color_scale(&cs);
	// create new image in memory
	plot_mandelbrot(&fr);
	// replace image shown
	mlx_put_image_to_window(fr.display, fr.window, fr.image, 0, 0);
	mlx_key_hook(fr.window, handle_key, &fr);
	mlx_mouse_hook(fr.window, mouse_event, 0);
	mlx_loop(fr.display);
	return (0);
}
