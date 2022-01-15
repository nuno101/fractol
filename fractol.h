/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:16:37 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/15 21:39:45 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h> //used for exit
# include "mlx.h"
# include "math.h"
# include <stdio.h> //used for printf, atoi
# include <string.h> //used for strcmp 

typedef struct Windows
{
	void	*display;
	void	*window;
	/* https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html */
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	char	*fractal_set; 
	double	k_re;
	double	k_im;
	unsigned	int		size_x;
	unsigned	int		size_y;
	int	color_shift;
}	t_Window;

unsigned    int color_scale(unsigned int n);

#endif
