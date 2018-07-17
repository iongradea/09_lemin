/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 17:39:02 by igradea           #+#    #+#             */
/*   Updated: 2017/01/15 15:55:01 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
