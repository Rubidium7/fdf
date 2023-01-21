/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:33:43 by nlonka            #+#    #+#             */
/*   Updated: 2023/01/21 13:43:14 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_data
{
	void	*img;
	void	*img2;
	void	*mlx;
	void	*win;
	char	*addr;
	char	*addr2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x0;
	int		y0;
	int		x00;
	int		y00;
	int		x;
	int		y;
	int		xi;
	int		yi;
	int		xh;
	int		yh;
	int		begx;
	int		begy;
	int		delta_x;
	int		delta_y;
	int		diff;
	int		x_sz;
	int		y_sz;
	double	line;
	int		cline;
	int		leftover;
	int		line_size;
	int		relx;
	int		rely;
	char	**hold;
	int		**map;
	int		**map_x;
	int		**map_y;
	int		sq_sz;
	int		alt;
	int		screen_sz_x;
	int		screen_sz_y;
	int		fd;
	int		i2;
	int		deg;
	int		safe;
	int		mark;
	int		mark2;
	int		color;
	int		color2;
	int		color_diff;
	int		color_theme;
}	t_data;

void	mlx_start(t_data *img);
void	pixel_put(t_data *data, int x, int y, int color);
int		mouse(int keycode, int x, int y, t_data *img);
int		keypresses(int keycode, t_data *img);
int		direct_off(t_data *img);
void	move_it(t_data *img, int keycode);
void	parallel_mode(t_data *img);
int		print_color_themes(void);

void	number_sort(char **help, int i, t_data *img);
int		free_ar(char **help, int **ar, int i);
void	line_sizer(t_data *img, int *sxy);
void	color(t_data *img, int var);

void	print_ar(t_data *img);

void	hexes(char *str, int *i);
int		sort_out_map(t_data *img);
int		init_map(t_data *img);
void	xy_deals(t_data *img);
int		makear_xy(t_data *img);

int		print_fdf(t_data *img);
void	direct_lines(t_data *img);
void	straight_x(t_data *img);
void	up_x(t_data *img);
void	down_x(t_data *img);

void	to_where(t_data *img);
void	draw_straight(t_data *img, int *sxy, int *exy);
void	draw_steep(t_data *img, int *sxy, int *exy);
void	draw_flat(t_data *img, int *sxy, int *exy);
#endif
