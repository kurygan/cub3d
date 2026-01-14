/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 01:01:15 by mkettab           #+#    #+#             */
/*   Updated: 2026/01/14 23:01:23 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

uint32_t	raw_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (a << 24 | b << 16 | g << 8 | r);
}

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
	return(raw_rgba(r, g, b, a));
}
