/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2021/12/28 17:13:42 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	my_mlx_pixel_put(Fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mandelbrot(Fractal *f)
{
	printf("Hello\n");
	mlx_pixel_put(f->mlx, f->window, 0, 0, 1);
	//mlx_pixel_put(f.mlx, f.window, 0, 1, 1);
}

int	handle_key(int keycode, Fractal f)
{
	printf("set: %s", f.set);
	printf("key pressed %i", keycode);
	return (0);
}

/*void	close_and_exit(s)
{
	mlx_destroy_window(s.mlx, s.window);
}*/

int	main(int argc, char **argv)
{
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

	//printf("Hello\n");
	fr.mlx = mlx_init();
	fr.window = mlx_new_window(fr.mlx, fr.size_x, fr.size_y, "Fract-ol");
	fr.image = mlx_new_image(fr.mlx, fr.size_x, fr.size_y);
	fr.addr = mlx_get_data_addr(fr.image, &fr.bits_per_pixel, &fr.line_length, &fr.endian);
	my_mlx_pixel_put(&fr, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(fr.mlx, fr.window, fr.image, 0, 0);
	mlx_key_hook(fr.window, handle_key, &fr);
	mlx_loop(fr.mlx);
	return (0);
}
