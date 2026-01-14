/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:50:46 by mkettab           #+#    #+#             */
/*   Updated: 2026/01/14 23:07:00 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_texture_on_img(t_sys *sys, mlx_texture_t *tex, int x_pos, int y_pos)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;
	size_t		index;

	y = 0;
	while (y < tex->height)
	{
		x = 0;
		while (x < tex->width)
		{
			index = (y * tex->width + x) * 4;
			color = raw_rgba(
				tex->pixels[index],
				tex->pixels[index + 1],
				tex->pixels[index + 2],
				tex->pixels[index + 3]
			);
			if ((x + x_pos) < (uint32_t)sys->img->width && (y + y_pos) < (uint32_t)sys->img->height)
				mlx_put_pixel(sys->img, x + x_pos, y + y_pos, color);
			x++;
		}
		y++;
	}
}