/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:46:35 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/03 15:18:28 by mkettab          ###   ########.fr       */
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
# define ARG_ERR "Put Valid Number of Arguments\033[0m"
# define ARG_TYPE_ERR "Put Only .cub files that EXISTS\033[0m"
# define FILE_PARSE_ERR "Wrong informations inside file \033[0m"

typedef struct s_gc			t_gc;
typedef struct s_parse_data	t_parse_data;
typedef struct s_sys		t_sys;

// STRUCTS

typedef enum s_gc_type {
	MAP,
	BUFFER //For GNL
}	t_gc_type;

typedef struct s_parse_data {
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	**floor;
	char	**cieling;
	char	**map;
}	t_parse_data;

typedef struct s_sys {
	t_parse_data	*map;
	t_gc			*gc;
	t_gc_type		temp_type;
}	t_sys;


# include "parsing.h"
# include "garbage.h"

#endif