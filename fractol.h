/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:16:37 by nlouro            #+#    #+#             */
/*   Updated: 2021/12/28 17:26:14 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h> //used for exit
# include "mlx.h"

typedef struct Fractals 
{
	void	*mlx;
	void	*window;

	/* https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html */
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	char	*set;
	int		size_x;
	int		size_y;
	//int		ymin
}	Fractal;

# include <stdio.h> //used for printf
# include <string.h> //used for strcmp 

#endif
