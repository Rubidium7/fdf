/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:48:04 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:20:58 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

void	direct_lines(t_data *img)
{
	if (img->map[img->yi][img->xi] == img->map[img->yi][img->xi + 1] \
		|| img->xi + 1 >= img->x_sz)
		straight_x(img);
	else if (img->map[img->yi][img->xi] < img->map[img->yi][img->xi + 1])
		up_x(img);
	else
		down_x(img);
	img->map_x[img->yi][img->xi] = img->begx;
	img->map_y[img->yi][img->xi] = img->begy;
}

void	sort_color(t_data *img)
{
	if (img->map[img->yi][img->xi] == img->map[img->yi + 1][img->xi] && \
			img->map[img->yi][img->xi] == 0)
		color(img, 0);
	else if (img->map[img->yi][img->xi] == img->map[img->yi + 1][img->xi] && \
			img->map[img->yi][img->xi] != 0)
		color(img, 1);
	else if (img->map[img->yi][img->xi] == 0)
		color(img, 2);
}

void	y_tho(t_data *img)
{
	img->yi = 0;
	while (img->xi < img->x_sz)
	{
		while (img->yi + 1 < img->y_sz)
		{
			img->begx = img->map_x[img->yi][img->xi];
			img->begy = img->map_y[img->yi][img->xi];
			img->x = img->map_x[img->yi + 1][img->xi];
			img->y = img->map_y[img->yi + 1][img->xi];
			if (img->map[img->yi][img->xi] == img->map[img->yi + 1][img->xi] && \
					img->map[img->yi][img->xi] == 0)
				color(img, 0);
			else if (img->map[img->yi][img->xi] == \
					img->map[img->yi + 1][img->xi] \
					&& img->map[img->yi][img->xi] != 0)
				color(img, 1);
			else
				color(img, 2);
			to_where(img);
			img->yi += 1;
		}
		img->yi = 0;
		img->xi += 1;
	}
}

int	print_fdf(t_data *img)
{	
	if (img->mark)
	{
		if (!init_map(img) || !sort_out_map(img))
			return (0);
	}
	xy_deals(img);
	while (img->yi < img->y_sz)
	{
		while (img->xi + 1 < img->x_sz)
		{
			direct_lines(img);
			img->xi += 1;
		}
		img->map_x[img->yi][img->xi] = img->x;
		img->map_y[img->yi][img->xi] = img->y;
		img->x = img->x0 - ((img->yi + 1) * \
				(img->sq_sz * cos(img->deg * (M_PI / 180))));
		img->y = img->y0 + ((img->yi + 1) * \
				(img->sq_sz * sin(img->deg * (M_PI / 180))));
		img->xi = 0;
		img->yi += 1;
	}
	y_tho(img);
	return (1);
}
