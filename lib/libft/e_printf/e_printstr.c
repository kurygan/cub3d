/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_printstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:56:30 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/16 13:58:35 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	e_putstr(char *str)
{
	int	count;

	if (!str)
		return (e_putstr("(null)"));
	count = ft_strlen(str);
	while (*str)
		write(STDERR_FILENO, str++, 1);
	return (count);
}

int	e_putchar(char c)
{
	write(STDERR_FILENO, &c, 1);
	return (1);
}

int	e_putptr(void *ptr)
{
	uintptr_t	converted;

	converted = (uintptr_t) ptr;
	if (!ptr)
		return (e_putstr("(nil)"));
	write(STDERR_FILENO, "0x", 2);
	return (e_puthex((unsigned long)converted, 1) + 2);
}
