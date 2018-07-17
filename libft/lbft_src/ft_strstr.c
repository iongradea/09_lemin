/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 17:39:02 by igradea           #+#    #+#             */
/*   Updated: 2017/01/01 18:12:16 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	if (big[0] == '\0')
		return (NULL);
	if (big[0] != little[0])
		return (ft_strstr(big + 1, little));
	while (big[i] == little[i])
	{
		if (little[i + 1] == '\0')
			return ((char*)big);
		i++;
	}
	return (ft_strstr(big + 1, little));
}
