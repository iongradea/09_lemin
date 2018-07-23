/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:36:22 by igradea           #+#    #+#             */
/*   Updated: 2017/09/07 04:48:51 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem-in.h"

void    ft_prt_tab(char **tab)
{
  int   i;

  i = -1;
  ft_printf("ft_prt_tab\n");
  while (tab[++i])
    ft_printf("%s\n", tab[i]);
}

void    ft_print_tab_int(int **tab)
{
  int i;
  int j;
  int len;

  len = ft_arrlen((char**)tab);
  i = -1;
  j = -1;
  while (++i < len)
  {
    while (++j < len)
      ft_printf("%d ", tab[i][j]);
    ft_printf("\n");
    j = -1;
  }
}
