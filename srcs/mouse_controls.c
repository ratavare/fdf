/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:40:09 by ratavare          #+#    #+#             */
/*   Updated: 2023/03/30 17:32:07 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_scroll(int key, int x, int y, t_data *data)
{
	t_mvar	vars;
	int		a;

	if (key == 4)
	{
		if (data->zoom > 20)
			a = 75;
		else
			a = 230;
		if (x > WIDTH / 2)
			data->shift_x -= (x - WIDTH / 2) / a;
		if (x < WIDTH / 2)
			data->shift_x += (WIDTH / 2 - x) / a;
		if (y > HEIGHT / 2)
			data->shift_y -= (y - HEIGHT / 2) / (a / 2.5);
		if (y < HEIGHT / 2)
			data->shift_y += (HEIGHT / 2 - y) / a;
		zoom_control(data, &vars, 4);
	}
	if (key == 5)
		zoom_control(data, &vars, 5);
	return (0);
}

int	mouse_press(int key, int x, int y, t_data *data)
{
	if (key == 4 || key == 5)
		mouse_scroll(key, x, y, data);
	if (key == 1)
	{
		data->mouse->mouse_press = 1;
	}
	return (0);
}

int	mouse_release(int key, int x, int y, t_data *data)
{
	(void)key;
	(void)x;
	(void)y;
	data->mouse->mouse_press = 0;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	t_mvar	vars;

	data->mouse->px = data->mouse->x;
	data->mouse->py = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->mouse_press == 1)
	{
		data->beta -= (x - data->mouse->px) * 0.002;
		data->alpha -= (y - data->mouse->py) * 0.002;
		my_mlx_clear_img(data);
		draw(&vars, data);
	}
	return (0);
}
