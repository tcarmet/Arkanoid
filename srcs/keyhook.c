/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:20:42 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 16:11:16 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	key_hook(t_all *all)
{
	glfwPollEvents();
	if (glfwGetKey(all->win.ptr, GLFW_KEY_LEFT) == GLFW_PRESS)
		set_ship_pos(&all->ship, all->ship.pos.x - SHIP_SPEED);
	if (glfwGetKey(all->win.ptr, GLFW_KEY_RIGHT) == GLFW_PRESS)
		set_ship_pos(&all->ship, all->ship.pos.x + SHIP_SPEED);
	// if (glfwGetKey(all->win.ptr, GLFW_KEY_SPACE) == GLFW_PRESS)
	// 	printf("SPACE\n");
}

void	key_callback(GLFWwindow *window, int key, int sc, int ac, int mod)
{
	(void)sc;
	(void)mod;
	if (key == GLFW_KEY_ESCAPE && ac == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
