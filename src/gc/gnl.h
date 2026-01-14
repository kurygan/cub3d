/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:25:11 by mkettab           #+#    #+#             */
/*   Updated: 2025/11/05 01:10:23 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_GNL_H
# define GC_GNL_H

# include "../../inc/cub3d.h"

int	gc_readstock(t_gnl **buf, int fd, t_sys *sys);
void	gc_addstock(char *str, t_gnl **buf, t_sys *sys);
void	gc_getlineappart(t_gnl *buf, char **str, t_sys *sys);
t_gnl	*gnl_getlast(t_gnl *list);
bool	gc_foundline(t_gnl *list);
void	gc_linegen(char **str, t_gnl *buf, t_sys *sys);

#endif