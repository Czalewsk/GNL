/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:36:57 by czalewsk          #+#    #+#             */
/*   Updated: 2016/11/28 15:06:13 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_remove_if(t_list **alst, int (*f)(t_list *elem), 
		void (*del)(void *, size_t))
{
	t_list		*cur;
	t_list		**prev;

	prev = &(*alst);
	cur = *prev;
	while (cur)
	{
		if (f(cur) == 1)
		{
			*prev = cur->next;
			cur->next = NULL;
			del(cur->content, cur->content_size);
			free(cur);
			cur = *prev;
		}
		else
		{
			cur = (*prev)->next;
			prev = &(*prev)->next;
		}
	}
}
