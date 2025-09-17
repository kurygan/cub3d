/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_printint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:35:21 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/16 13:53:51 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	e_putint(long d)
{
	long	first;

	first = d;
	if (d < 0)
	{
		d = -d;
		e_putchar('-');
	}
	if (d >= 10)
	{
		e_putint(d / 10);
		e_putint(d % 10);
	}
	if (d < 10)
		e_putchar(d + '0');
	return (ft_intlen(first));
}

int	e_putunsint(long d)
{
	if (d >= 10)
	{
		e_putunsint(d / 10);
		e_putunsint(d % 10);
	}
	if (d < 10)
		e_putchar(d + '0');
	return (ft_intunslen(d));
}

int	e_puthex(unsigned long c, int low)
{
	unsigned long	temp;
	char			*base;

	temp = c;
	if (low == 1)
		base = "0123456789abcdef";
	if (low == 0)
		base = "0123456789ABCDEF";
	if (c >= 16)
	{
		e_puthex(c / 16, low);
		e_puthex(c % 16, low);
	}
	if (c < 16)
		e_putchar(base[c]);
	return (ft_inthexlen(temp));
}
