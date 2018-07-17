/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 10:04:22 by exam              #+#    #+#             */
/*   Updated: 2017/07/24 14:10:17 by igradea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	init_var(char *tab, int *i, int *index)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		tab[j] = j + '0';
		j++;
	}
	while (j < 16)
	{
		tab[j] = j - 10 + 'A';
		j++;
	}
	*i = 0;
	*index = 0;
}

int		itoa_compute(int value, int base, int nb, char **str)
{
	char	tab[16];
	int		tab_i[64];
	int		index;
	int		i;

	init_var(tab, &i, &index);
	while (value != 0)
	{
		tab_i[i] = value % base;
		value = value / base;
		i++;
	}
	*str = (char *)malloc(sizeof(char) * (i + nb));
	i--;
	if (nb == 1)
		(*str)[index++] = '-';
	while (i >= 0)
	{
		(*str)[index] = tab[tab_i[i]];
		i--;
		index++;
	}
	(*str)[index] = '\0';
	return (index);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		nb;

	str = NULL;
	nb = 0;
	if (value < 0 && base == 10)
		nb = 1;
	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	if (value == 0)
		return ("0");
	if (value < 0)
		value *= -1;
	itoa_compute(value, base, nb, &str);
	return (str);
}
