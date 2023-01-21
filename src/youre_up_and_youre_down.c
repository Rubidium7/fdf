/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   youre_up_and_youre_down.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:35:12 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:20:44 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	up_x(t_data *img)
{
	if (img->xi == 0)
		img->y -= (img->alt * img->map[img->yi][img->xi]);
	img->begx = img->x;
	img->begy = img->y;
	img->x += (int)round(cos(img->deg * (M_PI / 180)) * img->sq_sz);
	img->y -= (img->alt * (img->map[img->yi][img->xi + 1] - \
				img->map[img->yi][img->xi])) - \
			(int)round(sin(img->deg * (M_PI / 180)) * img->sq_sz);
	color(img, 2);
	to_where(img);
}

void	down_x(t_data *img)
{
	if (img->xi == 0)
		img->y -= (img->alt * img->map[img->yi][img->xi]);
	img->begx = img->x;
	img->begy = img->y;
	img->x += (int)round(cos(img->deg * (M_PI / 180)) * img->sq_sz);
	img->y += (img->alt * (img->map[img->yi][img->xi] - \
				img->map[img->yi][img->xi + 1])) + \
			(int)round(sin(img->deg * (M_PI / 180)) * img->sq_sz);
	color(img, 2);
	to_where(img);
}

void	straight_x(t_data *img)
{
	if (img->xi == 0)
		img->y -= (img->alt * img->map[img->yi][img->xi]);
	img->begx = img->x;
	img->begy = img->y;
	img->x += (int)round(cos(img->deg * (M_PI / 180)) * img->sq_sz);
	img->y = img->y + (int)round(sin(img->deg * (M_PI / 180)) * img->sq_sz);
	if (img->map[img->yi][img->xi] == 0)
		color(img, 0);
	else
		color(img, 1);
	to_where(img);
}
