/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:08:32 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/05 01:22:52 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	check_file(char *av)
{
	int	temp_fd;

	if (ft_strrcmp(av, ".cub") || !ft_strrcmp(av, "/.cub") \
		|| !ft_strcmp(av, ".cub"))
		return (true);
	temp_fd = open(av, O_RDONLY, 0777);
	if (temp_fd == -1)
		return (true);
	close(temp_fd);
	return (false);
}

bool	assign_map(char *file, t_sys *sys)
{
	int	fd_data;
	int	fd_map;

	fd_data = open(file, O_RDONLY, 0777);
	fd_map = open(file, O_RDONLY, 0777);
	sys->data = parse_file(fd_data, sys);
	if (!sys->data)
		return (false);
	if (!parse_map(fd_map, fd_data, sys))
		return (false);
	return (true);
}

bool	check_args(char *av, t_sys *sys)
{
	if (check_file(av))
		return ((void)e_printf("%s%s\n", DEF_ERR, ARG_TYPE_ERR), true);
	if (!assign_map(av, sys))
		return ((void)e_printf("%s%s\n", DEF_ERR, FILE_PARSE_ERR), true);
	printf("map->north = %s", sys->data->north);
	return (false);
}
