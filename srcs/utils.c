/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:19:20 by ratavare          #+#    #+#             */
/*   Updated: 2023/11/21 23:57:24 by ratavare         ###   ########.fr       */
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
	ssize_t	i;

	i = write(2, "Invalid map name\n", 17);
	i = write(2, "Usage: ./fdf map/*map_name*\n", 29);
	(void)i;
	exit (0);
}

void	arg_error(void)
{
	ssize_t	i;

	i = write(2, "Invalid argument number\n", 24);
	(void)i;
	exit (0);
}

void	map_error(void)
{
	ssize_t	i;

	i = write(2, "Invalid map. (Not properly formated)\n", 37);
	(void)i;
	exit (0);
}
