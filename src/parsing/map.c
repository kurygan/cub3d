/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:20:29 by mkettab           #+#    #+#             */
/*   Updated: 2026/01/14 20:56:04 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	is_valid_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	assign_map(int fd, t_sys *sys)
{
	char	*line;
	size_t	y;
	size_t	map_size;

	line = skip_empty(fd, sys);
	y = 0;
	map_size = sys->data->map_size;
	while (y < map_size)
	{
		if (line_verif(line, y, sys)){
			printf("Failed Line: %s\n", line);
			return (false);
		}
		sys->map->map[y] = line;
		line = gc_gnl(fd, sys);
		y++;
	}
	if (!check_players(sys))
		return (false);
	return (true);
}

bool	parse_map(int fd_map, int fd_data, t_sys *sys)
{
	size_t	map_size;

	(void)fd_data;
	map_size = count_lines(fd_map, sys);
	printf("Map lenght: %zu\n", map_size);
	if (!map_size)
		return (false);
	sys->map = gc_malloc(&sys->gc, sizeof(t_map_data), PARSING, sys);
	sys->map->player = NULL;
	sys->map->map = (char **)gc_malloc(&sys->gc, sizeof(char *) * map_size, PARSING, sys);
	sys->data->map_size = map_size;
	if (!assign_map(fd_data, sys))
		return (false);
	return (true);
}

char	*skip_data(int fd, t_sys *sys)
{
	char	*line;

	line = gc_gnl(fd, sys);
	while (line_skip(line))
	{
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
	}
	return (line);
}

void	player_init(t_sys *sys, int x, int y, char card)
{
	t_player	*player;

	player = gc_calloc(sys, sizeof(t_player), PARSING);
	player->pos_x = (double)x;
	player->pos_y = (double)y;
	set_player_dir(player, card);
	if (player->dir_x == 0)
		player->fov_x = player->dir_y * -0.66;
	else if (player->dir_y == 0)
		player->fov_y = player->dir_x * 0.66;
	sys->map->player = player;
}