/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:48:39 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 16:04:44 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int		set_ball_pos(double *pos, double ret, double min, double max)
{
	if (ret < max && ret > min)
	{
		*pos = ret;
		return (1);
	}
	return (-1);
}

static void		ball_rebound(t_ball *ball, t_ship *ship)
{
	double mid_ship;
	double dx;

	mid_ship = ship->pos.x + (ship->width / 2);
	dx = mid_ship + ship->width / 2. - ball->pos.x;
	ball->vspeed.y *= -1;
	ball->vspeed.x = -dx * COEFF_D + SHIP_SPEED * COEFF_SPEED;
}

void			move_ball(t_ball *ball, t_ship *ship, t_map *map)
{
	if (set_ball_pos(&ball->pos.y, ball->pos.y + ball->vspeed.y, -1, 1) == -1)
		ball->vspeed.y = -ball->vspeed.y;
	if (set_ball_pos(&ball->pos.x, ball->pos.x + ball->vspeed.x, -1, 1) == -1)
		ball->vspeed.x = -ball->vspeed.x;
	if (check_ship_collision(ball, ship) == TRUE)
		ball_rebound(ball, ship);
	check_brick_collision(ball, map);
}
