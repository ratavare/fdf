/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:29:42 by ratavare          #+#    #+#             */
/*   Updated: 2023/03/24 12:15:00 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Checks if map is valid to prevent crashes and returns 
the width of the map (number of horizontal elements) */

int	check_map(char *filename)
{
	char	*line;
	int		fd;
	int		x;
	int		x2;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	x = word_count(line, 32);
	while (line)
	{
		x2 = word_count(line, 32);
		free (line);
		if (x != x2)
		{
			close(fd);
			return (0);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (x);
}

/* Checks the height of the map (number of vertical elements)
by checking how many lines there are in the file */

int	get_height(char *filename)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(filename, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		y++;
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (y);
}

/* Takes a line from the array created by ft_split and using ft_atoi inputs the
value into one of the z_matrix's lines through the read_file function */

void	fill_matrix(int *z_line, char	*line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, 32);
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free (nums[i]);
		i++;
	}
	free (nums);
}

/* Main function used to check and read the map files */

void	read_file(char	*filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		fd_error();
	data->y = get_height(filename);
	data->x = check_map(filename);
	if (data->x == 0)
		map_error();
	data->z_matrix = malloc(sizeof(int *) * (data->y + 1));
	i = 0;
	while (i < data->y)
		data->z_matrix[i++] = ft_calloc(sizeof(int), (data->x + 1));
	data->z_matrix[i] = NULL;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(data->z_matrix[i++], line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
