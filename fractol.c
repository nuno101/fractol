/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2021/12/28 22:42:55 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	my_mlx_pixel_put(Fractal *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
void	mandelbrot(Fractal *f)
{
	printf("Hello\n");
	//mlx_pixel_put(f->mlx, f->window, 0, 0, 1);
}
*/

int	handle_key(int keycode, Fractal *f)
{
	printf("key pressed %i", keycode);
	printf("set: %s", f->set);
	return (0);
}

/*void	close_and_exit(s)
{
	mlx_destroy_window(s.mlx, s.window);
}*/

int	main(int argc, char **argv)
{
    void    *mlx;
    void    *window;
	Fractal fr;
	//int size_x;
	//int size_y;

	if (argc < 2)
	{
		printf("ERROR: wrong args. Call as:\n fractol <fractal set> <params>\n"); 
		return (1);
	}
	if (strcmp(argv[1], "Julia") == 0)
		printf("Julia set");
	else if (strcmp(argv[1], "Mandelbrot") == 0)
		printf("Mandelbrot set");
	fr.set = argv[1];

	fr.size_x = 400;
	fr.size_y = 400;

	mlx = mlx_init();
	window = mlx_new_window(mlx, fr.size_x, fr.size_y, "Fract-ol");

	mlx_pixel_put(mlx, window, 5, 5, 0x00FF0000);
	mlx_pixel_put(mlx, window, 5, 15, 0x00FFFFFF);
	//fr.image = mlx_new_image(fr.mlx, fr.size_x, fr.size_y);
	//fr.addr = mlx_get_data_addr(fr.image, &fr.bits_per_pixel, &fr.line_length, &fr.endian);
	//my_mlx_pixel_put(&fr, 5, 5, 0x00FF0000);

	//mlx_put_image_to_window(fr.mlx, fr.window, fr.image, 0, 0);
	//mlx_put_image_to_window(mlx, window, fr.image, 0, 0);
	//mlx_key_hook(fr.window, handle_key, &fr);
	mlx_key_hook(window, handle_key, &fr);

	mlx_loop(mlx);
	return (0);
}
