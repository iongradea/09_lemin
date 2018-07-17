/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:30:42 by jberthie          #+#    #+#             */
/*   Updated: 2017/02/11 15:36:23 by jberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		i_am_separator(char c, char separator)
{
	if (c == separator)
		return (1);
	else
		return (0);
}

static int		ft_count_word(const char *str, char c)
{
	int			nb_words;

	nb_words = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (i_am_separator(*str, c))
			str++;
		else
		{
			nb_words += 1;
			while (!i_am_separator(*str, c) && *str)
				str++;
		}
	}
	return (nb_words);
}

char			**ft_strsplit_c(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		n;
	char	**new;

	i = 0;
	k = 0;
	n = ft_count_word(s, c);
	if ((new = (char **)malloc(sizeof(char *) * (n + 1))) == NULL)
		return (NULL);
	while (i < n)
	{
		j = 0;
		while (s[k] && i_am_separator(s[k], c))
			k++;
		while (s[k + j] && !i_am_separator(s[k + j], c))
			j++;
		new[i] = ft_strsub(s, k, j);
		k += j;
		i++;
	}
	new[i] = NULL;
	return (new);
}
