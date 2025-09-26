/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:04:52 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/20 12:07:44 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/garbage.h"

t_gc	*gc_getlast(t_gc **garbage)
{
	t_gc	*temp;

	if (!garbage || !*garbage)
		return (NULL);
	temp = *garbage;
	while (temp->right)
		temp = temp->right;
	return (temp);
}
