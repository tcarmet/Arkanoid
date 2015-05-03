/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 06:41:08 by jripoute          #+#    #+#             */
/*   Updated: 2015/05/03 20:43:12 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static GLFWwindow	*init_window(void)
{
	GLFWwindow *win;

	glfwSetErrorCallback(error_callback);
	if (glfwInit() == GL_FALSE)
		exit(EXIT_FAILURE);
	if ((win = glfwCreateWindow(800, 750, "Arkanoid", NULL, NULL)) == NULL)
		ft_error(CREATE_WINDOW);
	glfwMakeContextCurrent(win);
	glfwSwapInterval(1);
	glfwSetKeyCallback(win, key_callback);
	return (win);
}

void				init_ship(t_ship *ship)
{
	ship->pos.x = -SHIP_W;
	ship->pos.y = SHIP_OFFSET + SHIP_H;
	ship->vdir.x = 0;
	ship->vdir.y = 0;
	ship->height = SHIP_H * 2;
	ship->width = SHIP_W * 2;
}

void				init_ball(t_ball *ball)
{
	ball->pos.x = 0;
	ball->pos.y = SHIP_OFFSET + BALL_SIZE * 2;
	ball->vspeed.x = 0;
	ball->vspeed.y = 0;
	ball->radius = BALL_SIZE;
	ball->radius_pow_2 = BALL_SIZE * BALL_SIZE;
}

void				init_all(t_all *all)
{
	all->lv = NULL;
	all->cur = 0;
	all->life = 6;
	all->score = 0;
	parse_lvl(all, "./levels/");
	if (all->lv == NULL)
		ft_error(NO_MAP);
	init_ship(&all->ship);
	init_ball(&all->ball);
	all->win.ptr = init_window();
}
