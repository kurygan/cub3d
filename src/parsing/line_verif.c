/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 03:56:41 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/05 22:38:39 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	firstlast_lane(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '1' && line[x] != ' '){
			printf("Failed Char: %c at index %d\n", line[x], x + 1);
			return (true);}
		x++;
	}
	return (false);
}

bool	check_walls(char *line, t_sys *sys, size_t y)
{
	size_t	x;
	char	**map;

	x = 0;
	map = sys->map->map;
	while (line[x])
	{
		while (line[x] && line[x] == ' ')
		{
			if (map[y - 1][x] != '1' && map[y - 1][x] != ' ')
				return (true);
			x++;
		}
		if (line[x] && line[x] != '1')
			return (true);
		while (line[x] && line[x] != ' ')
		{
			if (map[y - 1][x] == ' ' && line[x] != '1')
				return (true);
			x++;
		}
		if (line[x - 1] && line[x - 1] != '1')
			return (true);
	}
	return (false);
}

bool	line_verif(char *line, size_t y, t_sys *sys)
{
	if (y == 0 || y == sys->data->map_size - 1)
		return (firstlast_lane(line));
	else
		return (check_walls(line, sys, y));
}

