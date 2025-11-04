/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:21:02 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/04 19:02:01 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_gnl.h"

t_gnl	*gnl_getlast(t_gnl *list)
{
	t_gnl	*last;

	last = list;
	while (last && last->next)
	{
		last = last->next;
	}
	return (last);
}

bool	gc_foundline(t_gnl *list)
{
	t_gnl	*current;

	if (!list)
		return (false);
	current = gnl_getlast(list);
	if (current->content[0] == '\n')
		return (true);
	return (false);
}

void	gc_linegen(char **str, t_gnl *buf, t_sys *sys)
{
	int	len;

	len = 0;
	while (buf && buf->content[0])
	{
		if (buf->content[0] == '\n')
		{
			len++;
			break ;
		}
		len++;
		buf = buf->next;
	}
	*str = gc_malloc(&sys->gc, sizeof(char) * (len + 1), MAP, sys);
}
