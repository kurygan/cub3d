/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:56:16 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/15 04:34:17 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**map_copy(char **src, t_sys *sys)
{
	char	**temp;
	int		i;

	temp = (char **)gc_malloc(&sys->gc, sizeof(char *) * sys->data->map_size, \
		PARSING, sys);
	i = 0;
	while (i < (int)sys->data->map_size)
	{
		temp[i] = gc_strdup(src[i], sys, PARSING);
		i++;
	}
	return (temp);
}