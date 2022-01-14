/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:16:37 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/14 11:17:44 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h> //used for exit
# include "mlx.h"
# include "math.h"
# include <stdio.h> //used for printf
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

	char	*set;
	unsigned	int		size_x;
	unsigned	int		size_y;
}	t_Window;

#endif
