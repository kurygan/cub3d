/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:42:00 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/30 02:52:32 by mkettab          ###   ########.fr       */
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

size_t	count_lines(int fd, t_sys *sys)
{
	char	*line;
	char	*valid_char;
	int		i;
	int		j;
	size_t	count;
	bool	error;

	valid_char = gc_strdup("10NWSE ", sys, MAP);
	//printf("%s$\n", valid_char);
	line = gc_gnl(fd, sys);
	printf("%s\n", line);
	count = 0;
	while (line)
	{
		i = 0;
		while (line[i])
		{
			error = true;
			j = 0;
			while (valid_char[j])
			{
				if (line[i] == valid_char[j])
				{
					printf("Valid Character Found: %c!\n", line[i]);
					error = false;
				}
				j++;
			}
			if (error)
				return (0);
			i++;
		}
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
		printf("%s\n", line);
		count++;
	}
	return (count);
}
