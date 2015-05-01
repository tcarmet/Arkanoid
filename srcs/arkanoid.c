/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:14:44 by tcarmet           #+#    #+#             */
/*   Updated: 2015/05/02 00:29:24 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		add_lvl(t_lvl **lv, char *sc)
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

void		aff_lvl(t_lvl *lv)
{
	while (lv)
	{
		ft_putendl(lv->fl);
		lv = lv->nt;
	}
}

void		parse_lvl(t_lvl **lv, char *sc)
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

void		creat_fenetre(void)
{
	GLFWwindow		*fn;

	fn = glfwCreateWindow(640,480, "Lvl 1", NULL, NULL);
	if (!fn)
	{
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(fn);
	while (!glfwWindowShouldClose(fn))
	{
		// LOL
	}
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
