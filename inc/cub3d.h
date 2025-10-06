/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:46:35 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/06 16:16:21 by mkettab          ###   ########.fr       */
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
# define ARG_ERR "Put Valid Number of Arguments.\033[0m"
# define ARG_TYPE_ERR "Put Only .cub files that EXISTS.\033[0m"
# define FILE_PARSE_ERR "Put all the informations needed.\033[0m"

typedef struct s_gc			t_gc;
typedef struct s_parse_data	t_parse_data;
typedef struct s_sys		t_sys;
typedef struct s_gnl		t_gnl;
typedef enum e_gc_type		t_gc_type;

// STRUCTS

typedef struct s_gc
{
	void		*mem; // Memory Allocated
	t_gc_type	type; // Type of Memory (If needed, add more type)
	t_sys		*sys;
	t_gc		*right;
	t_gc		*left;
}	t_gc;

typedef struct s_gnl
{
	char	*content;
	t_gnl	*next;
}	t_gnl;

typedef enum e_gc_type
{
	MAP,
	BUFFER
}	t_gc_type;

typedef struct s_parse_data
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	**floor;
	char	**cieling;
	char	**map;
}	t_parse_data;

typedef struct s_sys
{
	t_parse_data	*map;
	t_gc			*gc;
	t_gc_type		temp_type;
}	t_sys;

bool			check_args(char *av, t_sys *sys);
char			*gc_gnl(int fd, t_sys *sys);
int				count_lines(char *file, t_sys *sys);
t_parse_data	*parse_file(int fd, t_sys *sys);

t_gc			*gc_getlast(t_gc **garbage);
void			gc_free(void *mem, t_gc **garbage);
void			gc_carbonize(t_gc **garbage);
void			gc_carbonize_type(t_gc **garbage, t_gc_type type);
void			*gc_malloc(t_gc **garbage, size_t size, t_gc_type type, \
					t_sys *sys);
void			*gc_calloc(t_sys *sys, size_t size, t_gc_type type);
char			*gc_strdup(char	*str, t_sys *sys, t_gc_type type);
char			*gc_substr(char const *s, unsigned int start, size_t len,
					t_sys *sys);
char			**gc_split(char const *s, char c, t_sys *sys, t_gc_type type);

#endif