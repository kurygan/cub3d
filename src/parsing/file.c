/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:43:24 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/05 20:17:12 by mkettab          ###   ########.fr       */
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

void	verif_color(char *line, bool *filled_info, t_parse_data *map, t_sys *sys)
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

void	verif_whitespace_line(char *line, bool *filled_info)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_iswhitespace(line[i]))
			break;
		i++;
	}
	if (!line[i])
		*filled_info = true;
}

t_parse_data	*parse_file(char *file, t_sys *sys)
{
	t_parse_data	*map;
	int				fd;
	char			*line;
	bool			filled_info;

	map = gc_malloc(&sys->gc, sizeof(t_parse_data), MAP, sys);
	fd = open(file, O_RDONLY, 0777);
	line = gc_gnl(fd, sys);
	while (line)
	{
		filled_info = false;
		verif_text(line, &filled_info, map, sys);
		if (!filled_info)
			verif_color(line, &filled_info, map, sys);
		if (!filled_info)
			verif_whitespace_line(line, &filled_info);
		if (!filled_info)
			return (NULL);
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
	}
	return map;
}
