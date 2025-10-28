/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:35:23 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/28 23:46:57 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*gc_strdup(char	*str, t_sys *sys, t_gc_type type)
{
	char	*duped;

	duped = gc_malloc(&sys->gc, sizeof(char) * (ft_strlen(str) + 1), type, sys);
	duped = ft_memcpy(duped, str, ft_strlen(str));
	duped[ft_strlen(str)] = 0;
	return (duped);
}
