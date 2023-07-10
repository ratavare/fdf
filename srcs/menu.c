/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:03:24 by ratavare          #+#    #+#             */
/*   Updated: 2023/03/22 15:30:59 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->mlx_win;
	mlx_string_put(mlx, win, 65, y += 20, 0xF0FFFFFF, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, 0xF0FFFFFF, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, 0xF0FFFFFF, "Move: WASD");
	mlx_string_put(mlx, win, 15, y += 30, 0xF0FFFFFF,
		"Flatten: UP and DOWN Arrows");
	mlx_string_put(mlx, win, 15, y += 30, 0xF0FFFFFF, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, 0xF0FFFFFF, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, 0xF0FFFFFF, "Paralel or Isometric");
	mlx_string_put(mlx, win, 57, y += 25, 0xF0FFFFFF,
		"Change: I Key (Paralel as default)");
}
