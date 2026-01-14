/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:21:26 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/05 01:34:01 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	gc_free(void *mem, t_gc **garbage)
{
	t_gc	*temp;

	temp = *garbage;
	while (temp)
	{
		if (temp->mem == mem)
			break ;
		temp = temp->right;
	}
	if (mem)
		free(mem);
	if (temp)
		temp->mem = NULL;
}

void	gc_carbonize(t_gc **garbage)
{
	t_gc	*temp;
	t_gc	*next;

	if (!garbage || !*garbage)
		return ;
	temp = *garbage;
	while (temp)
	{
		next = temp->right;
		if (temp->mem)
			free(temp->mem);
		free(temp);
		temp = next;
	}
	*garbage = NULL;
}

void	gc_carbonize_type(t_gc **garbage, t_gc_type type)
{
	t_gc	*temp;

	if (!garbage || !*garbage)
		return ;
	temp = *garbage;
	while (temp)
	{
		if (temp->type == type)
		{
			free(temp->mem);
			temp->mem = NULL;
		}
		temp = temp->right;
	}
}
