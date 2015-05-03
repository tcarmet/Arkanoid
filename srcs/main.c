/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoppin <tcoppin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 13:31:02 by tcoppin           #+#    #+#             */
/*   Updated: 2015/05/03 16:12:03 by tcoppin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		main(void)
{
	t_all	all;

	all.lv = NULL;
	all.cur = 0;
	init_all(&all);
	while (!glfwWindowShouldClose(all.win.ptr))
		content_win(&all);
	glfwDestroyWindow(all.win.ptr);
	glfwTerminate();
	return (0);
}
