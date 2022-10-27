/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:32:52 by msoler-e          #+#    #+#             */
/*   Updated: 2022/10/27 11:32:55 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_data{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		sx;
	int		sy;
	double	c_im;
	double	c_re;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	freq;
	int		maxitera;
	int		red;
	int		green;
	int		blue;
	int		trans;
	double	zoom;
	double	crejulia;
	double	cimjulia;
	int		freeze_julia;
	int		fractal;
}	t_data;
void	ft_error(char *cnt, int error, t_data *tot);
#endif
