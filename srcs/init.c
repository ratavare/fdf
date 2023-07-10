/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:23:39 by ratavare          #+#    #+#             */
/*   Updated: 2023/03/22 15:42:19 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_mvar *vars, t_data *data, t_mouse *mouse, t_img *img)
{
	init_mvar(vars);
	init_data(data, mouse, img);
}

void	init_mvar(t_mvar *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->x1 = 0;
	vars->y1 = 0;
	vars->z = 0;
	vars->z1 = 0;
}

void	init_data(t_data *data, t_mouse *mouse, t_img *img)
{
	data->zoom = 1;
	data->shift_y = 0;
	data->shift_x = 0;
	data->img = img;
	data->img->mlx_img = 0;
	data->mouse = mouse;
	data->mouse->mouse_press = 0;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->z_div = 1;
	data->color = 0x00FFFFFF;
	data->color_flag = 0;
	data->mouse->mouse_press = 0;
	data->mouse->x = 0;
	data->mouse->y = 0;
	data->mouse->px = 0;
	data->mouse->py = 0;
	data->iso = 0;
}
