/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:35:54 by msoler-e          #+#    #+#             */
/*   Updated: 2022/11/25 12:35:55 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	textmenu(t_data *tot)
{
	ft_putstr_fd("\nMENU\n", 1);
	ft_putstr_fd("1-Mandelbrotn\n", 1);
	ft_putstr_fd("2-Julia\n", 1);
	ft_putstr_fd("3-Altres\n", 1);
	ft_error("\n", 2, tot);
}

void	menu(char **argv)
{
	ft_putstr_fd("MENU\n", 1);
	ft_putstr_fd(argv[1], 1);
}

void	ft_init_data(t_data *img)
{
	img->sx = 1920;
	img->sy = 1080;
	img->red = 1;
	img->freq = 0.3;
	img->green = 0;
	img->blue = 0;
	img->trans = 0;
	img->minre = -2.0;
	img->maxre = 1.0;
	img->minim = -1.2;
	img->maxim = img->minim + (img->maxre - img->minre)
		* ((img->sx) / (img->sy));
}

int	main(int argc, char **argv)
{
	t_data	img;
	int		x;
	int 	y;

	x = 0;
	ft_init_data(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.sx,
			img.sy, "miniRT");
	img.img = mlx_new_image(img.mlx, img.sx, img.sy);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);	
			y = y + 1;
		}
		x = x + 1;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 1L << 0, ft_hook, img);
	mlx_loop(img.mlx);
	if (argc == 2)
	{
		textmenu(&img);
		menu(argv);
	}
}
