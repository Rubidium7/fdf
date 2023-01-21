/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:17:35 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:21:15 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_straight(t_data *img, int *sxy, int *exy)
{
	int	xy;
	int	var;

	var = 0;
	if (img->delta_x < img->delta_y)
		img->diff = img->delta_y - 1;
	if (img->begx == img->x)
		var = 1;
	xy = sxy[var];
	while ((exy[var] + 1 < xy && exy[var] < sxy[var]) || \
			(exy[var] + 1 > xy && exy[var] > sxy[var]))
	{
		if (exy[var] > sxy[var])
			xy++;
		else
			xy--;
		if (sxy[0] == exy[0])
			pixel_put(img, sxy[0], xy, img->color);
		else
			pixel_put(img, xy, sxy[1], img->color);
	}
}

void	draw_flat(t_data *img, int *sxy, int *exy)
{
	line_sizer(img, sxy);
	while (img->yh != exy[1])
	{
		img->cline = img->line_size;
		if (img->leftover && (img->leftover \
				== img->delta_y || img->delta_y % 2 == 1))
		{
			img->cline += 1;
			img->leftover -= 1;
		}
		while (img->cline)
		{
			if (img->xh > exy[0])
				return ;
			pixel_put(img, img->xh, img->yh, img->color);
			img->cline -= 1;
			img->xh += 1;
		}
		img->yh += 1;
		img->delta_y -= 1;
		if (sxy[1] > exy[1])
			img->yh -= 2;
	}
}	

void	draw_steep(t_data *img, int *sxy, int *exy)
{
	line_sizer(img, sxy);
	while (img->xh != exy[0])
	{
		img->cline = img->line_size;
		if (img->leftover && (img->leftover == \
					img->delta_x || img->delta_x % 2 == 1))
		{
			img->cline += 1;
			img->leftover -= 1;
		}
		while (img->cline)
		{
			if ((sxy[1] > exy[1] && img->yh < exy[1]) \
					|| (sxy[1] < exy[1] && img->yh > exy[1]))
				return ;
			pixel_put(img, img->xh, img->yh, img->color);
			img->cline -= 1;
			img->yh += 1;
			if (sxy[1] > exy[1])
				img->yh -= 2;
		}
		img->xh += 1;
		img->delta_x -= 1;
	}
}

void	to_where(t_data *img)
{
	int	sxy[2];
	int	exy[2];

	sxy[0] = img->begx;
	sxy[1] = img->begy;
	exy[0] = img->x;
	exy[1] = img->y;
	img->delta_x = img->begx - img->x;
	img->delta_y = img->begy - img->y;
	if (img->x >= img->begx)
		img->delta_x = img->x - img->begx;
	if (img->y >= img->begy)
		img->delta_y = img->y - img->begy;
	if (!(img->delta_y) || !(img->delta_x) || \
			!(img->delta_y - 1) || !(img->delta_x - 1))
		draw_straight(img, sxy, exy);
	else if (img->delta_y <= img->delta_x && exy[0] < sxy[0])
		draw_flat(img, exy, sxy);
	else if (img->delta_y <= img->delta_x)
		draw_flat(img, sxy, exy);
	else if (img->delta_y > img->delta_x && exy[0] < sxy[0])
		draw_steep(img, exy, sxy);
	else
		draw_steep(img, sxy, exy);
}
