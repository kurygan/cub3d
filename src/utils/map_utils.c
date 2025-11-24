/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:42:00 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/06 19:40:28 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	line_skip(char *line)
{
	if (!*line || !ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) \
		|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3) \
		|| !ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (true);
	return (false);
}

bool	verif_char(char c, t_sys *sys)
{
	int		j;
	bool	error;
	char	*valid_char;

	valid_char = gc_strdup("NSEW10 ", sys, PARSING);
	error = true;
	j = 0;
	while (valid_char[j])
	{
		if (c == valid_char[j])
			error = false;
		j++;
	}
	gc_free(valid_char, &sys->gc);
	return (error);
}

size_t	count_lines(int fd, t_sys *sys)
{
	char	*line;
	int		i;
	size_t	count;

	line = skip_data(fd, sys);
	count = 0;
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (verif_char(line[i], sys))
				return (0);
			i++;
		}
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
		count++;
	}
	return (count);
}

char	*skip_empty(int fd, t_sys *sys)
{
	char	*line;
	line = gc_gnl(fd, sys);
	while (!*line)
	{
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
	}
	return (line);
}

bool	check_players(t_sys *sys)
{
	int		x;
	int		y;
	bool	player_found;

	y = 0;
	player_found = false;
	while (y < (int)sys->data->map_size)
	{
		x = 0;
		while (sys->map->map[y][x])
		{
			if (sys->map->map[y][x] == 'N' || sys->map->map[y][x] == 'S' || \
				sys->map->map[y][x] == 'E' || sys->map->map[y][x] == 'W')
			{
				if (player_found)
					return (false);
				player_found = true;
				player_init(sys, x, y, sys->map->map[y][x]);
			}
			x++;
		}
		y++;
	}
	return (player_found);
}
