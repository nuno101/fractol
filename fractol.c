/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:12:55 by nlouro            #+#    #+#             */
/*   Updated: 2021/12/27 16:24:40 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void *mlx_ptr;
	int size_x;
	int size_y;
	char *title = "Fract-ol";

	size_x = 1024;
	size_y = 768;

	printf("Hello\n");
	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, size_x, size_y, title);
	return (0);
}
