/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:49:18 by mkettab           #+#    #+#             */
/*   Updated: 2025/10/03 14:43:33 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include "cub3d.h"

typedef struct s_gc {
	void		*mem; // Memory Allocated
	t_gc_type	type; // Type of Memory (If needed, add more type)
	t_sys		*sys;
	t_gc		*right;
	t_gc		*left;
}	t_gc;

t_gc	*gc_getlast(t_gc **garbage);
void	gc_free(void *mem, t_gc **garbage);
void	gc_carbonize(t_gc **garbage);
void	gc_carbonize_type(t_gc **garbage, t_gc_type type);
void	*gc_malloc(t_gc **garbage, size_t size, t_gc_type type, t_sys *sys);
void	*gc_calloc(t_sys *sys, size_t size, t_gc_type type);
char	*gc_strdup(char	*str, t_sys *sys, t_gc_type type);
char	*gc_substr(char const *s, unsigned int start, size_t len,
			t_sys *sys);
char	**gc_split(char const *s, char c, t_sys *sys, t_gc_type type);

#endif