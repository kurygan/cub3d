/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 01:01:15 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/24 01:52:06 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

uint32_t	rgb_converter(char	**rgb)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	if (!rgb[2])
		return (0);
	a = 255;
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r == -1 || g == -1 || b == -1)
		return (0);
	return (a << 24 | b << 16 | g << 8 | r);
}
