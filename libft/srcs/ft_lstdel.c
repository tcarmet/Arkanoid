/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 19:19:21 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/03 19:19:33 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list			*el;
	t_list			*next;
	t_list			**ptr;

	if (alst)
	{
		el = *alst;
		while (el)
		{
			next = el->next;
			ptr = &el;
			ft_lstdelone(ptr, del);
			el = next;
		}
		*alst = NULL;
	}
}
