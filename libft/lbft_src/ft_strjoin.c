/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:09:03 by igradea           #+#    #+#             */
/*   Updated: 2017/08/30 14:11:03 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*res;

	i = 0;
	len_s1 = (int)ft_strlen(s1);
	len_s2 = (int)ft_strlen(s2);
	if (!(res = (char*)malloc(sizeof(*res) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[i + len_s1] = s2[i];
		i++;
	}
	res[len_s1 + len_s2] = '\0';
	return (res);
}
