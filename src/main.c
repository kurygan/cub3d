/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:01:24 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/21 23:22:14 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_sys	*sys;

	if (ac != 2)
		return ((void)e_printf("%s%s\n", DEF_ERR, ARG_ERR), 1);
	sys = malloc(sizeof(t_sys));
	ft_memset(sys, 0, sizeof(t_sys));
	if (check_args(av[1], sys))
		return (gc_carbonize(&sys->gc), free(sys), 1);
	if (!lib_init(sys))
		return (gc_carbonize(&sys->gc), free(sys), 1);
	mlx_loop(sys->mlx);
	gc_carbonize(&sys->gc);
	free(sys);
	return (0);
}
