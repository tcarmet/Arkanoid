/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 21:23:57 by tcarmet           #+#    #+#             */
/*   Updated: 2015/05/03 22:29:12 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <sys/types.h>
# include <stdlib.h>
# include <math.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft.h"
# include <sys/uio.h>

int				get_next_line(int const fd, char **line);

#endif
