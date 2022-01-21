/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 07:44:13 by nlouro            #+#    #+#             */
/*   Updated: 2022/01/21 10:44:23 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_Window *fr, double z)
{
	fr->rmin = z * fr->rmin;
	fr->rmax = z * fr->rmax;
	fr->imin = z * fr->imin;
	fr->imax = z * fr->imax;
}

void	reset_zoom(t_Window *fr)
{
	fr->rmin = -2.0;
	fr->rmax = 1.0;
	fr->imin = -1.2;
	fr->imax = 1.2;
}

void	shift_raxis(t_Window *fr, double s)
{
	fr->rmin = s + fr->rmin;
	fr->rmax = s + fr->rmax;
}

void	shift_iaxis(t_Window *fr, double s)
{
	fr->imin = s + fr->imin;
	fr->imax = s + fr->imax;
}
