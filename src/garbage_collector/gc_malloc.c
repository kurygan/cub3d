/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:56:13 by mkettab           #+#    #+#             */
/*   Updated: 2026/01/14 20:11:00 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	*gc_malloc(t_gc **garbage, size_t size, t_gc_type type, t_sys *sys)
{
	t_gc		*temp;
	void		*mem;

	temp = malloc(sizeof(t_gc));
	mem = malloc(size);
	if (!mem || !temp)
	{
		gc_carbonize(garbage);
		e_printf("%sMalloc Failed\n", DEF_ERR);
		exit(1);
	}
	temp->right = NULL;
	temp->left = NULL;
	temp->mem = mem;
	temp->type = type;
	temp->sys = sys;
	if (!*garbage)
		*garbage = temp;
	else
	{
		sys->last->right = temp;
		temp->left = sys->last;
	}
	sys->last = temp;
	return (mem);
}

void	*gc_calloc(t_sys *sys, size_t size, t_gc_type type)
{
	void	*mem;

	mem = gc_malloc(&sys->gc, size, type, sys);
	ft_memset(mem, 0, size);
	return (mem);
}
