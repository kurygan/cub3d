/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:13:13 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/24 01:53:17 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	lib_init(t_sys *sys)
{
	sys->mlx = mlx_init(800, 600, "Cube en troisieme dimension", false);
	if (!sys->mlx)
		return ((void)e_printf("%s%s\n", DEF_ERR, INIT_ERR), false);
	sys->textures->north = mlx_load_png(sys->data->north);
	sys->textures->west = mlx_load_png(sys->data->west);
	sys->textures->south = mlx_load_png(sys->data->south);
	sys->textures->east = mlx_load_png(sys->data->east);
	if (!sys->textures->north || !sys->textures->east || !sys->textures->south \
		|| !sys->textures->west)
		return ((void)e_printf("%s%s\n", DEF_ERR, TEXT_ERR), false);
	sys->textures->floor = rgb_converter(sys->data->floor);
	sys->textures->ceiling = rgb_converter(sys->data->ceiling);
	return (true);
}