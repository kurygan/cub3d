/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:19:29 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/04 19:05:45 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc_gnl.h"

char	*gc_gnl(int fd, t_sys *sys)
{
	static t_gnl	*buf;
	char			*fin_line;
	int				error;
	int				readed;

	fin_line = NULL;
	readed = 0;
	error = gc_readstock(&buf, fd, sys, &readed);
	if (error != 1)
		return (NULL);
	gc_getlineappart(buf, &fin_line, sys);
	gc_carbonize_type(&sys->gc, BUFFER);
	if (fin_line && fin_line[0] == 0 && readed == 0)
		return (NULL);
	//printf("%s\n", fin_line);
	return (fin_line);
}

int	gc_readstock(t_gnl **buf, int fd, t_sys *sys, int *readed)
{
	char	*str;

	*readed = 1;
	while (*readed > 0)
	{
		if (gc_foundline(*buf))
			return (1);
		str = gc_malloc(&sys->gc, BUFFER_SIZE + 1, BUFFER, sys);
		*readed = (int)read(fd, str, BUFFER_SIZE);
		//printf("%d\n", *readed);
		if (-1 == *readed)
			return (0);
		if (!buf && !*readed)
			return (0);
		str[*readed] = 0;
		gc_addstock(str, buf, sys);
	}
	return (1);
}

void	gc_addstock(char *str, t_gnl **buf, t_sys *sys)
{
	t_gnl	*last;
	t_gnl	*new;

	new = gc_malloc(&sys->gc, sizeof(t_gnl), BUFFER, sys);
	new->next = NULL;
	new->content = str;
	last = gnl_getlast(*buf);
	if (!last)
		last = new;
	else
		last->next = new;
}

void	gc_getlineappart(t_gnl *buf, char **str, t_sys *sys)
{
	size_t	i;
	t_gnl	*temp;

	if (!buf)
		return ;
	gc_linegen(str, buf, sys);
	i = 0;
	temp = buf;
	while (temp && temp->content[0])
	{
		(*str)[i++] = temp->content[0];
		temp = temp->next;
	}
	(*str)[i] = 0;
}
