/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:13:13 by mkettab           #+#    #+#             */
/*   Updated: 2026/01/14 23:06:43 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	init_img(t_sys *sys)
{
	sys->img = mlx_new_image(sys->mlx, WIDTH, HEIGHT);
	if (!sys->img)
		return (false);
	if (mlx_image_to_window(sys->mlx, sys->img, 0, 0) < 0)
		return (false);
	return (true);
}

bool	lib_init(t_sys *sys)
{
	sys->mlx = mlx_init(WIDTH, HEIGHT, "Cube en troisieme dimension", false);
	if (!sys->mlx)
		return ((void)e_printf("%s%s\n", DEF_ERR, INIT_ERR), false);
	sys->textures = gc_malloc(&sys->gc, sizeof(t_texture), PARSING, sys);
	sys->textures->north = mlx_load_png(sys->data->north);
	sys->textures->west = mlx_load_png(sys->data->west);
	sys->textures->south = mlx_load_png(sys->data->south);
	sys->textures->east = mlx_load_png(sys->data->east);
	if (!sys->textures->north || !sys->textures->east || !sys->textures->south \
		|| !sys->textures->west)
		return ((void)e_printf("%s%s\n", DEF_ERR, TEXT_ERR), false);
	sys->textures->floor = rgb_converter(sys->data->floor);
	sys->textures->ceiling = rgb_converter(sys->data->ceiling);
	if (!init_img(sys))
		return ((void)e_printf("Failed to load image and/or display\n"), false);
	return (true);
}
