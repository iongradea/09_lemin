/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb_words.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:42:38 by igradea           #+#    #+#             */
/*   Updated: 2017/01/13 17:10:12 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_count_nb_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		while (s[i] == c && s[i])
			i++;
		if (i != 0 && s[i - 1] == c && s[i] != c && s[i])
		{
			count++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}
