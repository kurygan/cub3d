/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 00:47:29 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/28 22:11:43 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*gc_substr(char const *s, unsigned int start, size_t len,
		t_sys *sys)
{
	unsigned int	i;
	char			*non_const_s;
	char			*subbed;

	if (!s)
		return (NULL);
	i = 0;
	non_const_s = (char *)s;
	if (ft_strlen(s) <= start)
		return (gc_strdup("", sys, sys->temp_type));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	subbed = gc_malloc(&sys->gc, sizeof(char) * len + 1, sys->temp_type, sys);
	while (i < start && non_const_s[i])
		i++;
	ft_memcpy(subbed, s + start, len);
	subbed[len] = 0;
	return (subbed);
}
