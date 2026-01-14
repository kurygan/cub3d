/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:13:13 by mkettab           #+#    #+#             */
/*   Updated: 2026/01/14 22:34:33 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	init_img(mlx_t *mlx, mlx_image_t *img)
{
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (false);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		return (false);
	return (true);
}

bool	lib_init(t_sys *sys)
{
	sys->mlx = mlx_init(800, 600, "Cube en troisieme dimension", false);
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
	if (!init_img(sys->mlx, sys->img))
		return ((void)e_printf("Failed to load image and/or display\n"), false);
	return (true);
}
