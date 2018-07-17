/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:19:46 by igradea           #+#    #+#             */
/*   Updated: 2017/01/11 16:43:28 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp->next;
	}
	*alst = NULL;
}
