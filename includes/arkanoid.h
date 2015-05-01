/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:08:45 by tcarmet           #+#    #+#             */
/*   Updated: 2015/05/01 23:33:21 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H

# define ARKANOID_H

# include "libft.h"
# include <dirent.h>
# include <math.h>
# include <GLFW/glfw3.h>

typedef struct	s_lvl
{
	struct s_lvl	*nt;
	struct s_lvl	*bf;
	char			*fl;
}				t_lvl;

typedef struct	s_map
{
	struct s_map	*nt;
	int				x;
	int				y;
}				t_map;

#endif
