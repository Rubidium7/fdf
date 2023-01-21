/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:34:29 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:43:40 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->screen_sz_x)
		return ;
	if (y < 0 || y >= img->screen_sz_y)
		return ;
	if (img->mark)
		dst = img->addr + (y * img->line_length + \
				x * (img->bits_per_pixel / 8));
	else
		dst = img->addr2 + (y * img->line_length \
				+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	move_it(t_data *img, int keycode)
{
	int	var;

	var = 70;
	if (keycode == 13)
		img->y00 -= var;
	else if (keycode == 0)
		img->x00 -= var;
	else if (keycode == 1)
		img->y00 += var;
	else if (keycode == 2)
		img->x00 += var;
	else if (keycode == 126)
		img->alt += 1;
	else if (keycode == 125)
		img->alt -= 1;
	else if (keycode == -1 && img->sq_sz > 0)
	{
		img->alt -= 2;
		img->sq_sz -= 15;
	}
	else if (keycode == -2)
	{
		img->alt += 2;
		img->sq_sz += 15;
	}
}

void	color_press(t_data *img, int keycode)
{
	if (keycode > 17 && keycode < 22)
		img->color_theme = keycode - 17;
	else if (keycode == 23)
		img->color_theme = 5;
	else if (keycode == 22)
		img->color_theme = 6;
	else if (keycode == 26)
		img->color_theme = 7;
	if (img->color_theme == 1)
		ft_printf("1. Defaultest but not the leastest :)\n");
	if (img->color_theme == 2)
		ft_printf("2. orca\n");
	if (img->color_theme == 3)
		ft_printf("3. optimus prime\n");
	if (img->color_theme == 4)
		ft_printf("4. greyscale\n");
	if (img->color_theme == 5)
		ft_printf("5. omg that's them those coding colors\n");
	if (img->color_theme == 6)
		ft_printf("6. totoro forest\n");
	if (img->color_theme == 7)
		ft_printf("7. it's a trap\n");
}

int	keypresses(int keycode, t_data *img)
{
	if (keycode == 8)
		return (print_color_themes());
	if (keycode == 53)
		return (direct_off(img));
	else if (keycode == 29)
		parallel_mode(img);
	else if (keycode == 124 && img->mark2)
		img->deg += 3;
	else if (keycode == 123 && img->mark2)
		img->deg -= 3;
	else if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move_it(img, keycode);
	else if (keycode == 126 || keycode == 125 || keycode == -1 || keycode == -2)
		move_it(img, keycode);
	else if ((keycode > 17 && keycode < 24) || keycode == 26 || keycode == 28)
		color_press(img, keycode);
	else
		return (0);
	img->mark = 0;
	img->img2 = mlx_new_image(img->mlx, img->screen_sz_x, img->screen_sz_y);
	img->addr2 = mlx_get_data_addr(img->img2, &img->bits_per_pixel, \
			&img->line_length, &img->endian);
	print_fdf(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img2, 0, 0);
	return (0);
}

int	mouse(int keycode, int x, int y, t_data *img)
{
	int	z;

	z = x;
	z = y;
	if (keycode == 4)
		keycode = -1;
	else if (keycode == 5)
		keycode = -2;
	else
		return (0);
	keypresses(keycode, img);
	return (1);
}
