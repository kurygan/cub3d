/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:08:32 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/26 17:34:07 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	check_file(char *av)
{
	int temp_fd;
	if (ft_strrcmp(av, ".cub") || !ft_strrcmp(av, "/.cub")\
		|| !ft_strcmp(av, ".cub"))
		return true;
	temp_fd = open(av, O_RDONLY, 0777);
	if (temp_fd == -1)
		return true;
	close(temp_fd);
	return false;
}

void	assign_map(char *file, t_sys *sys)
{
	int	line_count = count_lines(file, sys);
	printf("%d\n", line_count);
}

bool	check_args(char *av, t_sys *sys)
{
	if (check_file(av))
		return ((void)e_printf("%s\n%s\n", DEF_ERR, ARG_TYPE_ERR), true);
	assign_map(av, sys);
	return false;
}