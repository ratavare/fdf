/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:36:02 by ratavare          #+#    #+#             */
/*   Updated: 2023/03/16 14:03:22 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(t_mvar vars, t_data *data)
{
	int	z;
	int	z1;

	z = data->z_matrix[(int)vars.y][(int)vars.x];
	z1 = data->z_matrix[(int)vars.y1][(int)vars.x1];
	if (z >= 2 || z1 >= 2)
		data->color = 0x00FFAAFF;
	if (z >= 4 || z1 >= 4)
		data->color = 0x00FF88FF;
	if (z >= 6 || z1 >= 6)
		data->color = 0x00FF44FF;
	if (z >= 8 || z1 >= 8)
		data->color = 0x00FF00FF;
	if (z <= 0 || z1 <= 0)
		data->color = 0x00FFFFFF;
}
