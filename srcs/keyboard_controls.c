/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:51 by ratavare          #+#    #+#             */
/*   Updated: 2023/07/10 17:02:56 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_control(t_data *data, t_mvar *vars, int flag)
{
	if (flag == 0)
		data->shift_y += 10;
	if (flag == 1)
		data->shift_y -= 10;
	if (flag == 2)
		data->shift_x -= 10;
	if (flag == 3)
		data->shift_x += 10;
	data->color_flag = 0;
	my_mlx_clear_img(data);
	draw(vars, data);
}

void	zoom_control(t_data *data, t_mvar *vars, int flag)
{
	int	zflag;

	zflag = 1;
	if (data->zoom == 1)
	{
		if (flag == 4 && zflag)
			data->zoom += 1;
		zflag = 0;
	}
	if (data->zoom > 50)
		data->zoom--;
	if (flag == 4 && zflag)
		data->zoom += 1;
	if (flag == 5 && zflag)
		data->zoom -= 1;
	data->color_flag = 0;
	my_mlx_clear_img(data);
	draw(vars, data);
}

void	z_div_control(t_data *data, t_mvar *vars, int flag)
{
	if (flag == 6)
		data->z_div += 0.5;
	if (!(data->z_div < 2))
	{
		if (flag == 7)
			data->z_div -= 0.5;
	}
	data->color_flag = 0;
	my_mlx_clear_img(data);
	draw(vars, data);
}

void	change_proj(t_data *data, t_mvar *vars)
{
	if (data->iso == 0)
		data->iso = 1;
	else
		data->iso = 0;
	data->color_flag = 0;
	my_mlx_clear_img(data);
	draw(vars, data);
}
