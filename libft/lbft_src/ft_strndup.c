/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:36:25 by igradea           #+#    #+#             */
/*   Updated: 2016/11/08 20:01:19 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

char	*ft_strndup(char const *s1, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s1[i] != '\0' && i < n)
		i++;
	n = i;
	dup = (char*)malloc(sizeof(char) * (i + 1));
	if (dup == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}
