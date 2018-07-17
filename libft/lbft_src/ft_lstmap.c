/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:25:00 by igradea           #+#    #+#             */
/*   Updated: 2017/01/15 18:02:53 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list_begin;
	t_list	*new_list_elem;
	t_list	*buf;
	t_list	*tmp;

	buf = (*f)(lst);
	if (!(new_list_begin = ft_lstnew(buf->content, buf->content_size)))
		return (NULL);
	new_list_elem = new_list_begin;
	lst = lst->next;
	while (lst)
	{
		tmp = new_list_elem;
		buf = (*f)(lst);
		if (!(new_list_elem = ft_lstnew(buf->content, buf->content_size)))
			return (NULL);
		tmp->next = new_list_elem;
		lst = lst->next;
	}
	return (new_list_begin);
}
