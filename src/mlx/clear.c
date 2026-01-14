/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:37:57 by mkettab           #+#    #+#             */
/*   Updated: 2026/01/14 22:39:44 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_texture(t_texture *t)
{
	if (t->north)
		mlx_delete_texture(t->north);
	if (t->east)
		mlx_delete_texture(t->east);
	if (t->south)
		mlx_delete_texture(t->south);
	if (t->west)
		mlx_delete_texture(t->west);
}

void	mlx_clear(t_sys *sys)
{
	free_texture(sys->textures);
}