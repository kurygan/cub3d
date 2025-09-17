/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:08:32 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/16 14:00:44 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	check_file(char *av)
{
	int temp_fd;
	if (ft_strrcmp(av, ".cub"))
		return true;
	temp_fd = open(av, O_RDONLY, 0777);
	if (temp_fd == -1)
		return true;
	close(temp_fd);
	return false;
}

bool	check_args(char *av)
{
	if (check_file(av))
		return ((void)e_printf("%s\n%s\n", DEF_ERR, ARG_TYPE_ERR), true);
	return false;
}