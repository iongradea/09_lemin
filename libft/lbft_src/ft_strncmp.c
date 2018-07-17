/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:17:36 by igradea           #+#    #+#             */
/*   Updated: 2017/01/02 13:07:24 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if ((int)n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < (int)n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
