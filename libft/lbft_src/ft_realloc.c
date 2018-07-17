/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:27:44 by igradea           #+#    #+#             */
/*   Updated: 2017/02/14 17:03:49 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_realloc(char *ptr, size_t size)
{
	size_t	i;
	char	*ptr2;

	i = 0;
	if (!(ptr2 = (void*)malloc(size)))
		return (NULL);
	ft_bzero(ptr2, size);
	while (i < size && ((unsigned char*)ptr)[i])
	{
		((unsigned char*)ptr2)[i] = ((unsigned char*)ptr)[i];
		i++;
	}
	free(ptr);
	return (ptr2);
}
