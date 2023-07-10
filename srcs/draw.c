/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:47:08 by ratavare          #+#    #+#             */
/*   Updated: 2023/07/10 17:02:46 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_mvar vars, t_data *data)
{
	float	x_step;
	float	y_step;
	float	max;

	vars.z = data->z_matrix[(int)vars.y][(int)vars.x];
	vars.z1 = data->z_matrix[(int)vars.y1][(int)vars.x1];
	project(&vars, data);
	x_step = (vars.x1 - vars.x);
	y_step = (vars.y1 - vars.y);
	if (mod(x_step) > mod(y_step))
		max = mod(x_step);
	else
		max = mod(y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(vars.x - vars.x1) || (int)(vars.y - vars.y1))
	{
		my_mlx_pixel_put(data, vars.x, vars.y, data->color);
		vars.x += x_step;
		vars.y += y_step;
	}
}

void	draw(t_mvar *vars, t_data *data)
{
	vars->y = 0;
	while (vars->y < data->y)
	{
		vars->x = 0;
		while (vars->x < data->x)
		{
			if (vars->x < data->x - 1)
			{
				vars->x1 = vars->x + 1.01;
				vars->y1 = vars->y;
				bresenham(*vars, data);
			}
			if (vars->y < data->y - 1)
			{
				vars->x1 = vars->x;
				vars->y1 = vars->y + 1.01;
				bresenham(*vars, data);
			}
			vars->x++;
		}
		vars->y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->mlx_img, 0, 0);
	print_menu(data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		dst = data->img->addr + (y * data->img->l_length \
			+ x * (data->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_clear_img(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->l_length, &data->img->endian);
}
