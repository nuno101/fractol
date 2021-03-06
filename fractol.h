/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:16:37 by nlouro            #+#    #+#             */
/*   Updated: 2022/02/10 17:32:20 by nlouro           ###   ########.fr       */
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
# include "ft_atof.h"
# include "ft_strncmp.h"
# include "ft_printf.h"

/*
 * Minilibx docs
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
 * bpp - bits per pixel
 * ll - line length
 */
typedef struct Windows
{
	void			*display;
	void			*window;
	void			*image;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
	char			*fractal_set;
	double			k_re;
	double			k_im;
	int				size_x;
	int				size_y;
	unsigned int	max_iter;
	double			rmin;
	double			rmax;
	double			imin;
	double			imax;
	unsigned int	*scale[16];
	int				clr_shift;
}	t_Window;

typedef struct Coordinates
{
	int		px;
	int		py;
	double	c_re;
	double	c_im;
}	t_Coordinates;

void			plot_fractal(t_Window *fr);
void			my_mlx_pixel_put(t_Window *fr, int x, int y, int color);
void			plot_image(t_Window *fr);
void			init_window(t_Window *f);
void			set_clr_scale(t_Window *fr);
unsigned int	clr_scale(t_Window *fr, unsigned int n);
void			zoom(t_Window *fr, double z);
void			reset_zoom(t_Window *fr);
void			shift_raxis(t_Window *fr, double s);
void			shift_iaxis(t_Window *fr, double s);
void			zoom_from(t_Window *fr, double px, double py, double z);
int				handle_keypress(int keycode, t_Window *fr);
int				mouse_event(int button, int x, int y, void *param);

#endif
