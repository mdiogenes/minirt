/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:48:45 by msoler-e          #+#    #+#             */
/*   Updated: 2022/11/25 12:36:00 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minirt.h"

void	ft_move(int keycode, t_data *tot)
{
	if (keycode == 123)
	{
		tot->minre = tot->minre + (0.1 * tot->zoom);
		tot->maxre = tot->maxre + (0.1 * tot->zoom);
	}
	if (keycode == 124)
	{
		tot->minre = tot->minre - (0.1 * tot->zoom);
		tot->maxre = tot->maxre - (0.1 * tot->zoom);
	}
	if (keycode == 126)
	{
		tot->minim = tot->minim - (0.1 * tot->zoom);
		tot->maxim = tot->maxim - (0.1 * tot->zoom);
	}
	if (keycode == 125)
	{
		tot->minim = tot->minim + (0.1 * tot->zoom);
		tot->maxim = tot->maxim + (0.1 * tot->zoom);
	}
}

void	ft_itera(int keycode, t_data *tot)
{
	if (keycode == 69)
		tot->maxitera = tot->maxitera + 10;
	if (keycode == 78)
		tot->maxitera = tot->maxitera - 10;
	if (keycode == 49)
		tot->freeze_julia = 0;
}

int	ft_hook(int keycode, t_data *tot)
{
	if (keycode == 53)
		ft_error("\n", 1, tot);
	return (0);
}

void	ft_loop_zoom(t_data *tot, int mouscode)
{
	if (mouscode == 4)
	{
		if (tot->zoom > 1)
			tot->zoom = 1;
		else
			tot->zoom = tot->zoom - 0.01;
	}
	if (mouscode == 5)
	{
		if (tot->zoom < 1)
			tot->zoom = 1;
		else
			tot->zoom = tot->zoom + 0.01;
	}
	if (tot->fractal == 2)
		ft_fractaljulia(tot);
	if (tot->fractal == 3)
		ft_fractolburnship(tot);
	if (tot->fractal == 1)
		ft_fractolmandel(tot);
}

int	ft_mouse_handler(int mouscode, int x, int y, t_data *tot)
{
	double	centim;
	double	centre;

	if (mouscode == 1 && tot->freeze_julia == 1)
		tot->freeze_julia = 3;
	if (tot->fractal == 2 && mouscode == 1 && tot->freeze_julia == 0)
		ft_mouse_julia(tot, x, y);
	if (mouscode != 1)
	{
		tot->c_im = tot->maxim - y * (tot->maxim - tot->minim) / (tot->sy - 1);
		tot->c_re = tot->minre + x * (tot->maxre - tot->minre) / (tot->sx - 1);
		tot->maxre = tot->maxre * tot->zoom;
		tot->minre = tot->minre * tot->zoom;
		tot->minim = tot->minim * tot->zoom;
		tot->maxim = tot->minim + (tot->maxre - tot->minre)
			* ((tot->sx) / (tot->sy));
		centre = (tot->maxre - tot->minre) / 2;
		centim = (tot->maxim - tot->minim) / 2;
		tot->minre = tot->c_re - centre;
		tot->maxre = tot->c_re + centre;
		tot->maxim = tot->c_im + centim;
		tot->minim = tot->c_im - centim;
		ft_loop_zoom(tot, mouscode);
	}
	return (0);
}
