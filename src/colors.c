/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:44:32 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:01:26 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	color_0(t_data *img, int color)
{
	if (color == 1)
		img->color = 0x00AB9FC6;
	else if (color == 2)
		img->color = 0x004D4DFF;
	else if (color == 3)
		img->color = 0x00FFFFFF;
	else if (color == 4)
		img->color = 0x00333333;
	else if (color == 5)
		img->color = 0x00737373;
	else if (color == 6)
		img->color = 0x00BFBFBF;
	else if (color == 7)
		img->color = 0x00ECDFA3;
}

void	color_diff_flat(t_data *img, int color)
{
	if (color == 1)
		img->color2 = 0x0098AA71;
	else if (color == 2)
		img->color2 = 0x008080FF;
	else if (color == 3)
		img->color2 = 0x00BCF6F0;
	else if (color == 4)
		img->color2 = 0x00E6E6E6;
	else if (color == 5)
		img->color2 = 0x00333333;
	else if (color == 6)
		img->color2 = 0x0053943E;
	else if (color == 7)
		img->color2 = 0x00DFA3EC;
}

void	color(t_data *img, int var)
{
	color_diff_flat(img, img->color_theme);
	color_0(img, img->color_theme);
	if (var == 1)
		img->color = img->color2;
	if (var == 2 && img->color_theme == 1)
		img->color = 0x008371AA;
	if (var == 2 && img->color_theme == 2)
		img->color = 0x00CC7722;
	if (var == 2 && img->color_theme == 3)
		img->color = 0x00FFB3C1;
	if (var == 2 && img->color_theme == 4)
		img->color = 0x00808080;
	if (var == 2 && img->color_theme == 5)
		img->color = 0x0000CC00;
	if (var == 2 && img->color_theme == 6)
		img->color = 0x003E947F;
	if (var == 2 && img->color_theme == 7)
		img->color = 0x00ECA3B0;
}
