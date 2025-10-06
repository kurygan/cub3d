/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:47:30 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/05 20:30:48 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	count_lines(char *file, t_sys *sys)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		return (0);
	line = gc_gnl(fd, sys);
	count = 0;
	while (line)
	{
		count++;
		gc_free(line, &sys->gc);
		line = gc_gnl(fd, sys);
	}
	return (count);
}
