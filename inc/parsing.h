/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:45:33 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/26 16:57:33 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_gnl t_gnl;

typedef struct s_gnl
{
	char	*content;
	t_gnl	*next;
}	t_gnl;

bool	check_args(char *av, t_sys *sys);
char	*gc_gnl(int fd, t_sys *sys);
int		count_lines(char *file, t_sys *sys);

#endif