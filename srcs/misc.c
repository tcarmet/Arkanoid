/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:05:18 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 16:31:42 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	ft_next_level(t_all *all)
{
	if (all->lv->nt != NULL)
	{
		all->lv = all->lv->nt;
		all->cur = 0;
	}
}

void	aff_lvl(t_lvl *lv)
{
	while (lv)
	{
		ft_putendl(lv->fl);
		lv = lv->nt;
	}
}
