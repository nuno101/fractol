/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/06 18:12:46 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	my_mlx_pixel_put(Fractal *fr, int x, int y, int color)
{
	char	*dst;

	dst = fr->addr + (y * fr->line_length + x * (fr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	handle_key(int keycode, void *param)
{
	void *p;

	p = param;
	//printf("key pressed %i", keycode);
	if (keycode == 53)
		exit(0);
	else
		return(0);
}

int mouse_event(int button, int x, int y, void *param)
{
	void *p;

	p = param;
    // Whenever the event is triggered, print the value of button to console.
    printf("button: %i %i %i", x, y, button);
	return (0);
}

int	main(int argc, char **argv)
{
    void    *display; // connection
    void    *window;
	Fractal fr;

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

	fr.size_x = 640;
	fr.size_y = 480;

	display= mlx_init();
	window = mlx_new_window(display, fr.size_x, fr.size_y, "Fract-ol");
	// add color to a couple pixels
	mlx_pixel_put(display, window, 5, 5, 0x00FF0000);
	mlx_pixel_put(display, window, 5, 15, 0x00FFFFFF);
	// create new image in memory
	fr.image = mlx_new_image(display, fr.size_x, fr.size_y);
	fr.addr = mlx_get_data_addr(fr.image, &(fr.bits_per_pixel), &(fr.line_length), &(fr.endian));

	printf("bpp: %i\n", fr.bits_per_pixel);
	printf("line_length: %i\n", fr.line_length);
	printf("endian: %i\n", fr.endian);

	my_mlx_pixel_put(&fr, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&fr, 5, 15, 0x00FFFFFF);
	// replace image shown
	mlx_put_image_to_window(display, window, fr.image, 0, 0);
	mlx_key_hook(window, handle_key, &fr);
	mlx_mouse_hook(window, mouse_event, 0);
	mlx_loop(display);

	return (0);
}
