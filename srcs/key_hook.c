/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:43:15 by ratavare          #+#    #+#             */
/*   Updated: 2023/07/10 17:02:14 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_hooks(t_data data)
{
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_hook(data.mlx_win, KeyRelease, \
		KeyReleaseMask, handle_keyrelease, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, close_win, &data);
	mlx_hook(data.mlx_win, 4, ButtonPressMask, mouse_press, &data);
	mlx_hook(data.mlx_win, 5, ButtonReleaseMask, mouse_release, &data);
	mlx_hook(data.mlx_win, 6, PointerMotionMask, mouse_move, &data);
	mlx_loop(data.mlx_ptr);
}

int	handle_keyrelease(int key, t_data *data)
{
	t_mvar	vars;

	if (key == XK_Escape)
		close_win(data);
	if (key == XK_i)
		change_proj(data, &vars);
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	t_mvar	vars;

	if (key == XK_s)
		shift_control(data, &vars, 0);
	if (key == XK_w)
		shift_control(data, &vars, 1);
	if (key == XK_a)
		shift_control(data, &vars, 2);
	if (key == XK_d)
		shift_control(data, &vars, 3);
	if (key == XK_equal || key == XK_KP_Add)
		zoom_control(data, &vars, 4);
	if (key == XK_minus || key == XK_KP_Subtract)
		zoom_control(data, &vars, 5);
	if (key == XK_Down)
		z_div_control(data, &vars, 6);
	if (key == XK_Up)
		z_div_control(data, &vars, 7);
	return (0);
}
