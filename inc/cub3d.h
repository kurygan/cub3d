/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:46:35 by mkettab           #+#    #+#             */
/*   Updated: 2025/09/16 13:59:57 by mkettab          ###   ########.fr       */
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

typedef struct _gc gc;

// STRUCTS

typedef enum {
	MAP
}	gc_type;

typedef struct _gc {
	void	*mem;
	gc_type	type;
	gc		*next;
	gc		*last;
}	gc;

// FUNCTIONS

bool	check_args(char *av);

#endif