/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:32:52 by msoler-e          #+#    #+#             */
/*   Updated: 2022/11/25 12:28:45 by msoler-e         ###   ########.fr       */
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
	int		sx; //tamany imatge
	int		sy;//tamany imatge
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	freq;
	int		red;
	int		green;
	int		blue;
	int		trans;
}	t_data;
void	ft_error(char *cnt, int error, t_data *tot);
int		ft_hook(int keycode, t_data *tot);
#endif
