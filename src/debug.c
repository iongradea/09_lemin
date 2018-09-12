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
  DEBUG ? ft_printf("launching ft_prt_tab ...\n") : DEBUG;
  while (tab[++i])
    ft_printf("%s\n", tab[i]);
}

void    ft_print_tab_int(int **tab)
{
  int i;
  int j;
  int len;

  DEBUG ? ft_printf("launching ft_print_tab_int ...\n") : DEBUG;
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

void  ft_print_djikstra(t_data *data)
{
  int i;

  DEBUG ? ft_printf("launching ft_print_djikstra ...\n") : DEBUG;
  i = -1;
  while (++i < data->nb_room)
    ft_printf("%s - %d - %d\n", data->room[i], data->dist[i], data->spt_set[i]);
}

void  ft_prt_path(t_data *data)
{
  int i;

  DEBUG ? ft_printf("launching ft_prt_path ...\n") : DEBUG;
  i = -1;
  while (data->path[++i])
    ft_printf("%s\n", data->path[i]);
}

void  ft_debug_prt_ant(t_data *data)
{
  int i;

  DEBUG ? ft_printf("launching ft_debug_prt_ant ...\n") : DEBUG;
  i = -1;
  while (++i < data->nb_ant)
    ft_printf("ant %d : %d\n", i, data->ant_pos_tab[i]);
}
