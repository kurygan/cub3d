/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:26:01 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/03 13:32:12 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	ft_count_words(char const *s, char c)
{
	int	counts;
	int	i;

	i = 0;
	counts = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			counts++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counts);
}

static char	**ft_free_all(char **splitted, int j)
{
	while (j-- > 0)
		free(splitted[j]);
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		start;
	int		j;

	if (!s)
		return (NULL);
	splitted = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!splitted)
		return (NULL);
	(void)0, i = 0, j = 0, start = 0;
	while (j < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		splitted[j] = ft_substr(s, start, i - start);
		if (!splitted[j])
			return (ft_free_all(splitted, j));
		j++;
	}
	return (splitted[j] = NULL, splitted);
}
