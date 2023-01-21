/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:23:32 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:41:50 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_size(t_data *img, int safe, int i)
{
	char	*buf;

	img->y_sz = 0;
	img->x_sz = 0;
	while (1)
	{
		buf = get_next_line(img->fd);
		if (!buf)
			break ;
		img->y_sz += 1;
		while (buf[i] && buf[i] != '\n')
		{
			hexes(buf, &i);
			while ((buf[i] < '0' || buf[i] > '9') && buf[i])
				i++;
			if (buf[i] >= '0' && buf[i] <= '9' && buf[i])
				safe += 1;
			while (buf[i] >= '0' && buf[i] <= '9' && buf[i])
				i++;
		}
		free(buf);
		if (img->y_sz == 1)
			img->x_sz = safe;
	}
	return (1);
}

int	sort_out_map(t_data *img)
{
	char	**help;
	int		i;

	i = 0;
	img->map = malloc (sizeof(int *) * img->y_sz);
	if (!(img->map))
		return (0);
	while (i != img->y_sz)
	{
		help = ft_split(img->hold[i], ' ');
		img->map[i] = malloc (sizeof(int) * img->x_sz);
		if (!help || !(img->map[i]))
			return (free_ar(help, img->map, i));
		number_sort(help, i, img);
		free_ar(help, NULL, 0);
		i++;
	}
	if (!(makear_xy(img)))
		return (0);
	return (1);
}

int	init_map(t_data *img)
{
	int	i;

	i = 0;
	img->hold = malloc (sizeof(char *) * img->y_sz);
	if (!(img->hold))
		return (0);
	while (i != img->y_sz)
	{
		img->hold[i] = get_next_line(img->fd);
		if (!(img->hold[i]))
			return (free_ar(img->hold, NULL, 0));
		i++;
	}
	img->x00 = 0;
	img->y00 = 0;
	img->deg = 30;
	img->safe = 30;
	img->sq_sz = 30;
	img->mark2 = 1;
	img->yi = 0;
	img->xi = 0;
	img->color_theme = 1;
	img->alt = 5;
	return (1);
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac != 2)
		return (write(1, "file needed\n", 12) - 12);
	img.fd = open(av[1], O_RDONLY);
	if (img.fd == -1)
		return (write(1, "File doesn't exist\n", 19) - 19);
	mlx_start(&img);
	count_size(&img, 0, 0);
	close(img.fd);
	img.fd = open(av[1], O_RDONLY);
	if (img.fd == -1)
		return (write(1, "Open malfunctioned\n", 19) - 19);
	print_fdf(&img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_mouse_hook(img.win, &mouse, &img);
	mlx_hook(img.win, 2, 1L << 0, &keypresses, &img);
	mlx_hook(img.win, 17, 0, &direct_off, &img);
	mlx_loop(img.mlx);
	return (direct_off(&img));
}
