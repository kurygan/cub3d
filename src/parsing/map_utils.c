/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:42:00 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/29 00:00:07 by mkettab          ###   ########.fr       */
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

size_t	count_lines(int fd, t_sys *sys, bool *error)
{
	char	*line;
	char	*valid_char;
	int		i;
	int		j;
	size_t	count;

	valid_char = gc_strdup("10NWSE ", sys, MAP);
	line = gc_gnl(fd, sys);
	i = 0;
	j = 0;
	*error = true;
	count = 0;
	while (line)
	{
		while (line[i])
		{
			while (valid_char[j])
			{
				if (valid_char[j] == line[i])
				{
					*error = false;
					break;
				}
				j++;
			}
			if (*error)
				return (count);
			i++;
		}
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
		count++;
	}
	return (count);
}
