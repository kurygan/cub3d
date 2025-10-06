/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:19:29 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/05 20:32:51 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_gnl.h"

char	*gc_gnl(int fd, t_sys *sys)
{
	static t_gnl	*buf;
	char			*fin_line;
	int				error;

	buf = NULL;
	fin_line = NULL;
	error = gc_readstock(&buf, fd, sys);
	if (error != 1)
		return (NULL);
	gc_getlineappart(buf, &fin_line, sys);
	gc_carbonize_type(&sys->gc, BUFFER);
	if (!(fin_line[0]))
	{
		buf = NULL;
		return (NULL);
	}
	return (fin_line);
}

int	gc_readstock(t_gnl **buf, int fd, t_sys *sys)
{
	char	*str;
	int		readed;

	readed = 1;
	while (!gc_foundline(*buf) && readed > 0)
	{
		str = gc_malloc(&sys->gc, 2, BUFFER, sys);
		readed = (int)read(fd, str, BUFFER_SIZE);
		if (-1 == readed)
			return (0);
		if (!buf && !readed)
			return (0);
		str[readed] = 0;
		gc_addstock(str, buf, readed, sys);
	}
	return (1);
}

void	gc_addstock(char *str, t_gnl **buf, int readed, t_sys *sys)
{
	int		i;
	t_gnl	*last;
	t_gnl	*new;

	new = gc_malloc(&sys->gc, sizeof(t_gnl), BUFFER, sys);
	new->next = NULL;
	new->content = gc_malloc(&sys->gc, sizeof(char) * (readed + 1), \
		BUFFER, sys);
	i = 0;
	while (str[i] && i < readed)
	{
		new->content[i] = str[i];
		i++;
	}
	new->content[i] = 0;
	if (!*buf)
	{
		*buf = new;
		return ;
	}
	last = gnl_getlast(*buf);
	last->next = new;
}

void	gc_getlineappart(t_gnl *buf, char **str, t_sys *sys)
{
	int	i;

	if (!buf)
		return ;
	gc_linegen(str, buf, sys);
	i = 0;
	while (buf)
	{
		(*str)[i++] = buf->content[0];
		buf = buf->next;
	}
	(*str)[i] = 0;
}
