/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:20:42 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 22:30:42 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	key_hook(t_all *all)
{
	glfwPollEvents();
	if (glfwGetKey(all->win.ptr, GLFW_KEY_LEFT) == GLFW_PRESS)
		set_ship_pos(all, all->ship.pos.x - SHIP_SPEED);
	if (glfwGetKey(all->win.ptr, GLFW_KEY_RIGHT) == GLFW_PRESS)
		set_ship_pos(all, all->ship.pos.x + SHIP_SPEED);
	if (glfwGetKey(all->win.ptr, GLFW_KEY_PAGE_UP) == GLFW_PRESS
		&& all->cur > 0)
		ft_next_level(all);
	if (glfwGetKey(all->win.ptr, GLFW_KEY_SPACE) == GLFW_PRESS && all->cur < 2)
	{
		all->cur = 2;
		all->ball.vspeed.x = BALL_SPEED;
		all->ball.vspeed.y = BALL_SPEED;
	}
}

void	key_callback(GLFWwindow *window, int key, int sc, int ac, int mod)
{
	(void)sc;
	(void)mod;
	if (key == GLFW_KEY_ESCAPE && ac == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
