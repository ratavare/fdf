/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:18:21 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/11 14:59:47 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Efficiency, color, menu, corrigir bug pyramide

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../get_next_line/get_next_line.h"

# define WIDTH	1920
# define HEIGHT	1080

typedef struct s_mvar
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
}	t_mvar;

typedef struct s_mouse
{
	int		mouse_press;
	int		x;
	int		y;
	int		px;
	int		py;

}	t_mouse;

typedef struct s_img
{
	void	*mlx_img;
	void	*mlx_clear;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	int		x;
	int		y;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		color_flag;
	int		shift_y;
	int		shift_x;
	float	z_div;
	int		iso;

	float	alpha;
	float	beta;
	float	gamma;

	t_mouse	*mouse;
	t_img	*img;

	void	*mlx_ptr;
	void	*mlx_win;
	int		i;
}	t_data;

// main.c
int		close_win(t_data *data);

// read_file.c
int		get_height(char	*filename);
int		check_map(char *filename);
void	fill_matrix(int *z_line, char	*line);
void	read_file(char	*filename, t_data *data);

// utils.c
int		word_count(char	*line, char c);
float	mod(float a);
void	fd_error(void);
void	arg_error(void);
void	map_error(void);

// draw.c
void	bresenham(t_mvar vars, t_data *data);
void	draw(t_mvar *vars, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_pixel_clear(t_data *data, int x, int y, int color);
void	my_mlx_clear_img(t_data *data);

// color.c
void	color(t_mvar vars, t_data *data);

// keyboard_controls.c
void	shift_control(t_data *data, t_mvar *vars, int flag);
void	zoom_control(t_data *data, t_mvar *vars, int flag);
void	z_div_control(t_data *data, t_mvar *vars, int flag);
void	change_proj(t_data *data, t_mvar *vars);

// mouse_controls.c
int		mouse_scroll(int key, int x, int y, t_data *data);
int		mouse_press(int key, int x, int y, t_data *data);
int		mouse_release(int key, int x, int y, t_data *data);
int		mouse_move(int x, int y, t_data *data);

// project.c
void	isometric(t_mvar *vars, t_data *data);
void	rotate_x(t_mvar *vars, t_data *data);
void	rotate_y(t_mvar *vars, t_data *data);
void	rotate_z(t_mvar *vars, t_data *data);
void	project(t_mvar *vars, t_data *data);

//init.c
void	init_vars(t_mvar *vars, t_data *data, t_mouse *mouse, t_img	*img);
void	init_mvar(t_mvar *vars);
void	init_data(t_data *data, t_mouse *mouse, t_img *img);

//menu.c
void	print_menu(t_data *data);

//key_hook.c
int		handle_keyrelease(int key, t_data *data);
int		handle_keypress(int key, t_data *data);
void	handle_hooks(t_data data);

#endif