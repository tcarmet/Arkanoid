/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <tcarmet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 19:20:30 by tcarmet           #+#    #+#             */
/*   Updated: 2015/04/03 19:20:31 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_lstiter(t_list *el, void (*f)(t_list *elem))
{
	t_list			*next;

	while (el)
	{
		next = el->next;
		f(el);
		el = next;
	}
}
