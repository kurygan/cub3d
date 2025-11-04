/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:43:24 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/05 20:41:31y mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	verif_text(char *line, bool *filled_info, t_parse_data *map, t_sys *sys)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		map->north = gc_strdup(line + 3, sys, MAP);
		*filled_info = true;
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		map->south = gc_strdup(line + 3, sys, MAP);
		*filled_info = true;
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		map->west = gc_strdup(line + 3, sys, MAP);
		*filled_info = true;
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		map->east = gc_strdup(line + 3, sys, MAP);
		*filled_info = true;
	}
}

void	verif_color(char *line, bool *filled_info, t_parse_data *map, \
	t_sys *sys)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		map->floor = gc_split(line + 2, ',', sys, MAP);
		*filled_info = true;
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		map->cieling = gc_split(line + 2, ',', sys, MAP);
		*filled_info = true;
	}
}

bool	parse_complete(t_parse_data *map)
{
	if (map->north && map->west && map->south && map->east && map->floor && \
		map->cieling)
		return (true);
	return (false);
}

t_parse_data	*parse_file(int fd, t_sys *sys)
{
	t_parse_data	*map;
	char			*line;
	bool			filled_info;

	map = gc_calloc(sys, sizeof(t_parse_data), MAP);
	line = gc_gnl(fd, sys);
	while (line)
	{
		filled_info = false;
		if (!line[0])
			filled_info = true;
		if (!filled_info && !parse_complete(map))
			verif_text(line, &filled_info, map, sys);
		if (!filled_info && !parse_complete(map))
			verif_color(line, &filled_info, map, sys);
		if (!filled_info && !parse_complete(map))
			return (NULL);
		else if (!filled_info)
			return (map);
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
	}
	return (NULL);
}
