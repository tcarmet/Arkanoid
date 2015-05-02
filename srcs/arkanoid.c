/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:14:44 by tcarmet           #+#    #+#             */
/*   Updated: 2015/05/02 14:16:03 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void			add_lvl(t_lvl **lv, char *sc)
{
	t_lvl			*ns;
	t_lvl			*tp;

	ns = (t_lvl *)ft_memalloc((sizeof(t_lvl)));
	ns->fl = sc;
	ns->nt = NULL;
	ns->bf = NULL;
	if ((*lv))
	{
		tp = (*lv);
		while ((*lv)->nt)
			(*lv) = (*lv)->nt;
		(*lv)->nt = ns;
		ns->bf = (*lv);
		(*lv) = tp;
	}
	else
		(*lv) = ns;
}

void			aff_lvl(t_lvl *lv)
{
	while (lv)
	{
		ft_putendl(lv->fl);
		lv = lv->nt;
	}
}

void			parse_lvl(t_lvl **lv, char *sc)
{
	DIR				*rp;
	struct dirent	*fc;

	if ((rp = opendir(sc)) != NULL)
	{
		while ((fc = readdir(rp)))
			if (!ft_strequ(fc->d_name, ".") && !ft_strequ(fc->d_name, ".."))
				add_lvl(lv, ft_strdup(fc->d_name));
		if (closedir(rp) == -1)
			exit(-1);
	}
}

static void		error_callback(int er, const char *dn)
{
	(void)er;
	ft_putendl_fd(dn, 2);
}

static void		key_callback(GLFWwindow* fn, int ky, int sc, int ac, int md)
{
	(void)sc;
	(void)md;
	if (ky == GLFW_KEY_ESCAPE && ac == GLFW_PRESS)
		glfwSetWindowShouldClose(fn, GL_TRUE);
}

void			creat_carre(double x, double y, double i, double j)
{
	glBegin(GL_TRIANGLE_STRIP);
	i = i / 6;
	j = j / 11;
	glVertex3f(-x - i, -y + j, 0);
	glVertex3f(x - i, -y + j, 0);
	glVertex3f(-x - i, y + j, 0);
	glVertex3f(x - i, y + j, 0);
}

void			contenu_window(GLFWwindow *fn)
{
	float			ratio;
	int				width;
	int				height;

	glfwGetFramebufferSize(fn, &width, &height);
	ratio = width / (float) height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	int j = 0;
	int i = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 7)
		{
			glLoadIdentity();
			creat_carre(0.08, 0.03, (double)-i, (double)j);
			glEnd();
			glLoadIdentity();
			creat_carre(0.08, 0.03, (double)i, (double)j);
			glEnd();
			i++;
		}
		j++;
	}
	glfwSwapBuffers(fn);
	glfwPollEvents();
}

void			creat_fenetre(void)
{
	GLFWwindow		*fn;

	glfwSetErrorCallback(error_callback);
	fn = glfwCreateWindow(640,480, "Lvl 1", NULL, NULL);
	if (!fn)
	{
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(fn);
	glfwSwapInterval(1);
	glfwSetKeyCallback(fn, key_callback);
	while (!glfwWindowShouldClose(fn))
		contenu_window(fn);
	glfwDestroyWindow(fn);
}

int			main(void)
{
	t_lvl			*lv;
	t_map			*mp;


	lv = NULL;
	mp = NULL;
	parse_lvl(&lv, "./levels/");
	if (!glfwInit()) 
		return (-1);
	creat_fenetre();
	glfwTerminate();
	return (0);
}
