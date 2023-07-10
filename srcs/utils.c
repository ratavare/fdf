/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:19:20 by ratavare          #+#    #+#             */
/*   Updated: 2023/03/23 16:27:10 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	word_count(char *line, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != c && (line[i + 1] == c || line[i + 1] == 0
				|| line[i + 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	fd_error(void)
{
	write(1, "Invalid map name\n", 17);
	write(1, "Usage: ./fdf map/*map_name*\n", 29);
	exit (0);
}

void	arg_error(void)
{
	write(1, "Invalid argument number\n", 24);
	exit (0);
}

void	map_error(void)
{
	write(1, "Invalid map. (Not properly formated)\n", 37);
	exit (0);
}
