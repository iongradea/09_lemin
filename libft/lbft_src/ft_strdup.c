/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:30:39 by igradea           #+#    #+#             */
/*   Updated: 2017/07/25 17:46:59 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;
	size_t	len;

	len = ft_strlen(src);
	if (!(ret = (char*)malloc(sizeof(*ret) * ((int)len + 1))))
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
