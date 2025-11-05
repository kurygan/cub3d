/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:42:00 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/05 02:58:53 by mkettab          ###   ########.fr       */
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

	valid_char = gc_strdup("NSEW10 ", sys, MAP);
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
