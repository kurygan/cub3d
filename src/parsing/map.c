/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:20:29 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/05 02:47:22 by mkettab          ###   ########.fr       */
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

bool	parse_map(int fd_map, int fd_data, t_sys *sys)
{
	size_t	loc_num;

	(void)fd_data;
	loc_num = count_lines(fd_map, sys);
	printf("Map lenght: %zu\n", loc_num);
	if (!loc_num)
		return (false);
	sys->map->map = (char *)gc_malloc(&sys->gc, sizeof(char *) * loc_num, MAP, sys);
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
		//printf("%s\n", line);
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
	}
	return (line);
}