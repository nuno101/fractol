/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:16:37 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/20 22:02:50 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h> //used for exit
# include "math.h"
# include "mlx.h"
# include "ft_isdigit.h"
# include "ft_atoi.h"
# include "ft_strncmp.h"
# include "ft_printf.h"

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
