/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:25:46 by igradea           #+#    #+#             */
/*   Updated: 2017/07/05 00:12:00 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n1, size_t n2)
{
	size_t	i;
	char	*new;

	i = -1;
	if (!(new = ft_strnew(n1 + n2)))
		return (NULL);
	new = ft_memcpy(new, s1, n1);
	while (++i < n2)
		new[n1 + i] = s2[i];
	return (new);
}
