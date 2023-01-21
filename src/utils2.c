/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:05:54 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:43:28 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	hexes(char *str, int *i)
{
	if (str[*i] != ',')
		return ;
	*i += 1;
	while (str[*i] != ' ' && str[*i] && str[*i] != '\n')
		*i += 1;
}

void	parallel_mode(t_data *img)
{
	if (img->mark2)
	{
		img->safe = img->deg;
		img->mark2 = 0;
		img->deg = 0;
		ft_printf("parallel mode: ON\n");
	}
	else
	{
		img->deg = img->safe;
		img->mark2 = 1;
		ft_printf("parallel mode: OFF\n");
	}
}

int	print_color_themes(void)
{
	ft_printf("\nPress the corresponding number for");
	ft_printf("the color theme you wish:\n\n");
	ft_printf("[1] defaultest but not the leastest :)\n");
	ft_printf("[2] orca\n");
	ft_printf("[3] optimus prime\n");
	ft_printf("[4] greyscale\n");
	ft_printf("[5] omg that's them those coding colors\n");
	ft_printf("[6] totoro forest\n");
	ft_printf("[7] it's a trapppp\n\n");
	return (0);
}

int	direct_off(t_data *img)
{
	free_ar(NULL, img->map, img->y_sz);
	free_ar(NULL, img->map_x, img->y_sz);
	free_ar(NULL, img->map_y, img->y_sz);
	exit(1);
}

int	makear_xy(t_data *img)
{
	int	i;

	i = 0;
	img->map_x = malloc(sizeof(int *) * img->y_sz);
	if (!(img->map_x))
		return (0);
	img->map_y = malloc(sizeof(int *) * img->y_sz);
	if (!(img->map_y))
	{
		free(img->map_x);
		return (0);
	}
	while (i != img->y_sz)
	{
		img->map_x[i] = malloc(sizeof(int) * img->x_sz);
		img->map_y[i] = malloc(sizeof(int) * img->x_sz);
		if (!(img->map_x[i]) || !(img->map_y[i]))
		{
			free_ar(NULL, img->map_x, i);
			free_ar(NULL, img->map_y, i);
			return (0);
		}
		i++;
	}
	return (1);
}
