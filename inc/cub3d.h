/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 03:54:28 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/15 04:34:37 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/***********************************INCLUDES***********************************/

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

/************************************DEFINE************************************/

# define DEF_ERR "Error\n\033[1;31m"
# define ARG_ERR "Put Valid Number of Arguments.\033[0m"
# define ARG_TYPE_ERR "Put Only .cub files that EXISTS.\033[0m"
# define FILE_PARSE_ERR "Put all the informations needed.\033[0m"

typedef struct s_gc			t_gc;
typedef struct s_parse_data	t_parse_data;
typedef struct s_sys		t_sys;
typedef struct s_gnl		t_gnl;
typedef struct s_array		t_array;
typedef struct s_player		t_player;
typedef enum e_gc_type		t_gc_type;
typedef enum e_orientation	t_card;

/***********************************STRUCTS************************************/

typedef enum e_gc_type
{
	PARSING,
	BUFFER
}	t_gc_type;

typedef enum e_orientation
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_card;

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

typedef struct s_parse_data
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	**floor;
	char	**cieling;
	size_t	map_size;
}	t_parse_data;

typedef struct s_map_data
{
	char		**map;
	t_player	*player;
}	t_map_data;

typedef struct s_player
{
	int		x;
	int		y;
	t_card	or;
}	t_player;

typedef struct s_sys
{
	t_parse_data	*data;
	t_map_data		*map;
	t_gc			*gc;
	t_gc_type		temp_type;
}	t_sys;

/***********************************COMMANDS***********************************/

// PARSING

bool			check_args(char *av, t_sys *sys);
char			*gc_gnl(int fd, t_sys *sys);
size_t			count_lines(int fd, t_sys *sys);
t_parse_data	*parse_file(int fd, t_sys *sys);
bool			parse_map(int fd_map, int fd_data, t_sys *sys);
bool			line_skip(char *line);
char			*skip_data(int fd, t_sys *sys);
bool			assign_map(int fd, t_sys *sys);
char			*skip_empty(int fd, t_sys *sys);
bool			line_verif(char *line, size_t y, t_sys *sys);
bool			check_players(t_sys *sys);
void			player_init(t_sys *sys, int x, int y, char card);
char			**map_copy(char **src, t_sys *sys);

// GARBAGE

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