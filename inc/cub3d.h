/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:46:35 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/26 17:28:53 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

// DEF

# define DEF_ERR "Error\n\033[1;31m"
# define ARG_ERR "Put Valid Number of Arguments\033[0;0m"
# define ARG_TYPE_ERR "Put Only .cub files that EXISTS\033[0;0m"

typedef struct s_gc		t_gc;
typedef struct s_map	t_map;
typedef struct s_sys	t_sys;

// STRUCTS

typedef struct s_map {
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	**map;
}	t_map;

typedef struct s_sys {
	t_map	*map;
	t_gc	*gc;
}	t_sys;

# include "parsing.h"
# include "garbage.h"

#endif