/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:21:02 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/06 19:39:57 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_gnl	*gnl_getlast(t_gnl *list)
{
	t_gnl	*last;

	last = list;
	while (last && last->next)
		last = last->next;
	return (last);
}

bool	gc_foundline(t_gnl *list)
{
	t_gnl	*current;
	int		i;

	if (!list)
		return (false);
	current = gnl_getlast(list);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

void	gc_linegen(char **str, t_gnl *buf, t_sys *sys)
{
	int	i;
	int	len;

	len = 0;
	while (buf)
	{
		i = 0;
		while (buf->content[i])
		{
			if (buf->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		buf = buf->next;
	}
	*str = gc_malloc(&sys->gc, sizeof(char) * (len + 1), PARSING, sys);
	(*str)[0] = 0;
}
