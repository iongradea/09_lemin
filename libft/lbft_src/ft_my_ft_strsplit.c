/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:13:41 by igradea           #+#    #+#             */
/*   Updated: 2017/08/30 14:18:27 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	void	ft_init_var(int *i, int *len, int *index)
{
	*i = 0;
	*len = 0;
	*index = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		len;
	int		index;
	int		count_wds;

	ft_init_var(&i, &len, &index);
	count_wds = ft_count_nb_words(s, c);
	if (!(res = (char**)malloc(sizeof(*res) * (count_wds + 1))))
		return (NULL);
	while (index < count_wds)
	{
		while (s[i] == c)
			i++;
		while (s[i + len] != c)
			len++;
		res[index] = ft_strsub(s, i, len);
		index++;
		i += len;
		len = 0;
	}
	res[index] = NULL;
	return (res);
}
