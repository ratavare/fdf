/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:33:08 by ratavare          #+#    #+#             */
/*   Updated: 2023/05/13 15:37:49 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_mvar	vars;
	t_mouse	mouse;
	t_img	img;

	init_vars (&vars, &data, &mouse, &img);
	if (ac != 2)
		arg_error();
	read_file(av[1], &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH,
			HEIGHT, "Filho da fruta");
	if (data.mlx_win == NULL)
	{
		free (data.mlx_win);
		return (1);
	}
	data.img->mlx_img = mlx_new_image(data.mlx_ptr, 1920, 1080);
	data.img->addr = mlx_get_data_addr(data.img->mlx_img, &data.img->bpp,
			&data.img->l_length, &data.img->endian);
	draw(&vars, &data);
	handle_hooks(data);
	mlx_loop(data.mlx_ptr);
}

int	close_win(t_data *data)
{
	int	i;

	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	i = 0;
	while (data->z_matrix[i])
	{
		free(data->z_matrix[i]);
		i++;
	}
	if (data->z_matrix)
		free(data->z_matrix);
	exit(0);
	return (0);
}
