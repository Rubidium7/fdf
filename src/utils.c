/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:00:05 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:27:58 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	xy_deals(t_data *img)
{	
	img->x0 = img->x00 + (img->screen_sz_x / 2);
	img->y0 = img->y00;
	img->x = img->x0;
	img->y = img->y0;
	img->yi = 0;
	img->xi = 0;
}

int	free_ar(char **help, int **ar, int i)
{
	int	i2;

	i2 = 0;
	if (ar)
	{
		while (i2 != i)
		{
			free(ar[i2]);
			i2++;
		}
		free(ar);
	}
	if (help)
	{
		while (help[i2])
		{
			free(help[i2]);
			i2++;
		}
		free(help);
	}
	return (0);
}

void	line_sizer(t_data *img, int *sxy)
{
	img->xh = sxy[0];
	img->yh = sxy[1];
	if (img->delta_x >= img->delta_y)
	{
		if (img->delta_y - 1 != 0)
		{
			img->line_size = (img->delta_x - 1) / (img->delta_y - 1);
			img->leftover = (img->delta_x - 1) % (img->delta_y - 1);
			return ;
		}
		img->line_size = img->delta_x - 1;
	}
	else
	{
		if (img->delta_x - 1 != 0)
		{
			img->line_size = (img->delta_y - 1) / (img->delta_x - 1);
			img->leftover = (img->delta_y - 1) % (img->delta_x - 1);
			return ;
		}
		img->line_size = img->delta_y - 1;
	}
	img->leftover = 0;
}

void	number_sort(char **help, int i, t_data *img)
{
	int	i2;

	i2 = 0;
	while (help[i2])
	{
		img->map[i][i2] = ft_atoi(help[i2]);
		i2++;
	}
}

void	mlx_start(t_data *img)
{
	img->mark = 1;
	img->screen_sz_x = 1920;
	img->screen_sz_y = 1080;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, img->screen_sz_x, \
			img->screen_sz_y, "fdf");
	img->img = mlx_new_image(img->mlx, img->screen_sz_x, \
			img->screen_sz_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel \
			, &img->line_length, &img->endian);
}
