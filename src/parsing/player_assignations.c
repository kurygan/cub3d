/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_assignations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:30:06 by mkettab           #+#    #+#             */
/*   Updated: 2026/01/14 20:32:51 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_player_dir(t_player *player, char card)
{
	if (card == 'N')
	{
		player->dir_y = -1;
		player->dir_x = 0;
	}
	if (card == 'S')
	{
		player->dir_y = 1;
		player->dir_x = 0;
	}
	if (card == 'E')
	{
		player->dir_y = 0;
		player->dir_x = 1;
	}
	if (card == 'W')
	{
		player->dir_y = 0;
		player->dir_x = -1;
	}
}