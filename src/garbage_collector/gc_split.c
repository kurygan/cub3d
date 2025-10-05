/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:46:41 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/03 14:57:41 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**gc_split(char const *s, char c, t_sys *sys, t_gc_type type)
{
	char	**splitted;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	sys->temp_type = type;
	splitted = gc_malloc(&sys->gc, sizeof(char *) * (ft_count_words(s, c) + 1), type, sys);
	start = 0;
	while (j < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		splitted[j] = gc_substr(s, start, i - start, sys);
		j++;
	}
	splitted[j] = NULL;
	return (splitted);
}
