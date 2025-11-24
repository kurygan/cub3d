/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:25:12 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/24 01:51:16 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	index;
	int	result;

	sign = 1;
	result = 0;
	if (*str == '-' && str[1])
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+' && str[1])
		str++;
	while (*str >= '0' && *str <= '9')
	{
		index = *str - '0';
		result = (result * 10) + index;
		str++;
	}
	if (*str)
		return (-1);
	return (result * sign);
}
