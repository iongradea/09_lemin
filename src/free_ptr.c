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

# include "../inc/lem-in.h"

void  ft_free_tab(char **tab)
{
  int i;

  DEBUG ? ft_printf("launching ft_free_tab ...\n") : DEBUG;
  i = 0;
  while (tab[i])
  {
    free(tab[i]);
    i++;
  }
  free(tab);
}

void  ft_free_tab_int(int **tab)
{
  int i;

  DEBUG ? ft_printf("launching ft_free_tab_int ...\n") : DEBUG;
  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
