/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:39:38 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/24 16:26:44 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_mvar *vars, t_data *data)
{
	int	py;
	int	py1;

	py = vars->y;
	py1 = vars->y1;
	vars->y = py * cos(data->alpha) + vars->z * sin(data->alpha);
	vars->z = -py * sin(data->alpha) + vars->z * cos(data->alpha);
	vars->y1 = py1 * cos(data->alpha) + vars->z1 * sin(data->alpha);
	vars->z1 = -py1 * sin(data->alpha) + vars->z1 * cos(data->alpha);
}

void	rotate_y(t_mvar *vars, t_data *data)
{
	int	px;
	int	px1;

	px = vars->x;
	px1 = vars->x1;
	vars->x = px * cos(data->beta) + vars->z * sin(data->beta);
	vars->z = -px * sin(data->beta) + vars->z * cos(data->beta);
	vars->x1 = px1 * cos(data->beta) + vars->z1 * sin(data->beta);
	vars->z1 = -px1 * sin(data->beta) + vars->z1 * cos(data->beta);
}

void	rotate_z(t_mvar *vars, t_data *data)
{
	int	px;
	int	py;
	int	px1;
	int	py1;

	px = vars->x;
	py = vars->y;
	px1 = vars->x1;
	py1 = vars->y1;
	vars->x = px * cos(data->gamma) - py * sin(data->gamma);
	vars->y = px * sin(data->gamma) + py * cos(data->gamma);
	vars->x1 = px1 * cos(data->gamma) - py1 * sin(data->gamma);
	vars->y1 = px1 * sin(data->gamma) + py1 * cos(data->gamma);
}

void	isometric(t_mvar *vars, t_data *data)
{
	float	temp;
	float	temp1;

	(void)data;
	temp = (vars->x - vars->y) * cos(0.6);
	vars->y = (vars->x + vars->y) * sin(0.6) - vars->z;
	temp1 = (vars->x1 - vars->y1) * cos(0.6);
	vars->y1 = (vars->x1 + vars->y1) * sin(0.6) - vars->z1;
	vars->x = temp;
	vars->x1 = temp1;
}

void	project(t_mvar *vars, t_data *data)
{
	if (data->color_flag == 0)
		color(*vars, data);
	else
		data->color = 0xFF000000;
	vars->x *= data->zoom;
	vars->y *= data->zoom;
	vars->x1 *= data->zoom;
	vars->y1 *= data->zoom;
	vars->z *= data->zoom;
	vars->z1 *= data->zoom;
	vars->z /= data->z_div;
	vars->z1 /= data->z_div;
	if (data->iso == 1)
		isometric(vars, data);
	rotate_x(vars, data);
	rotate_y(vars, data);
	rotate_z(vars, data);
	vars->x += 850 + data->shift_x;
	vars->x1 += 850 + data->shift_x;
	vars->y += 350 + data->shift_y;
	vars->y1 += 350 + data->shift_y;
}
