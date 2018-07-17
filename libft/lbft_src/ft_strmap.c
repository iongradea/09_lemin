/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:26:32 by igradea           #+#    #+#             */
/*   Updated: 2017/08/30 14:12:45 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(s);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		res[i] = (*f)(s[i]);
		i++;
	}
	return (res);
}
