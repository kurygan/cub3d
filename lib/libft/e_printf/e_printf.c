/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:58:53 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/16 13:53:09 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_args(char c, va_list *args)
{
	if (c == 'd' || c == 'i')
		return (e_putint(va_arg(*args, int)));
	else if (c == 's')
		return (e_putstr(va_arg(*args, char *)));
	else if (c == 'c')
		return (e_putchar(va_arg(*args, int)));
	else if (c == 'u')
		return (e_putunsint(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (e_puthex(va_arg(*args, unsigned int), 1));
	else if (c == 'X')
		return (e_puthex(va_arg(*args, unsigned int), 0));
	else if (c == '%')
		return (e_putchar('%'));
	else if (c == 'p')
		return (e_putptr(va_arg(*args, void *)));
	return (-1);
}

int	e_printf(const char *s, ...)
{
	int		final_len;
	int		arg_len;
	va_list	args;

	(void)0, final_len = 0, arg_len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			arg_len = ft_args(*(s + 1), &args);
			final_len += arg_len;
			s++;
		}
		else
		{
			write(STDERR_FILENO, s, 1);
			final_len++;
		}
		if (*s)
			s++;
	}
	return (final_len);
}

// int main(){
// 	ft_printf("ft_printf:");
// 	int printf42 = ft_printf(" %d ", INT32_MIN);
// 	printf("\nprintf:");
// 	int printfoff = printf(" %ld ", LONG_MIN);
// 	printf("\n");

// 	printf("ft_printf: %d\t", printf42);
// 	printf("printf: %d\n", printfoff);	
// }
