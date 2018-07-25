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

static void  ft_init_ant(t_data *data)
{
  int i;

  i = -1;
  DEBUG ? ft_printf("launching ft_init_ant ...\n") : DEBUG;
  if (!(data->ant_pos_tab = (int*)malloc(sizeof(int) * (data->nb_ant))))
    exit(0);
  while (++i < data->nb_ant)
    data->ant_pos_tab[i] = START_PATH_I;
}

static int  ch_all_ant_end(t_data *data)
{
  int i;

  i = -1;
  DEBUG ? ft_printf("launching ch_all_ant_end ...\n") : DEBUG;
  while (++i < data->nb_ant)
  {
    if (ANT_NOT_AT_END(i))
      return (FALSE);
  }
  return (TRUE);
}

static void  incr_ant_pos(t_data *data)
{
  int ant_i;

  ant_i = -1;
  DEBUG ? ft_printf("launching incr_ant_pos ...\n") : DEBUG;
  while (++ant_i < data->nb_ant)
  {
    DEBUG ? ft_printf("ant_i : %d\n", ant_i) : DEBUG;
    DEBUG ? ft_printf("ant_pos_tab[0] : %d\n", data->ant_pos_tab[0]) : DEBUG;
    if (ANT_NOT_AT_START(ant_i) && ANT_NOT_AT_END(ant_i))
    {
      DEBUG ? ft_printf("ant_i : %d\n", ant_i) : DEBUG;
      data->ant_pos_tab[ant_i]++;
    }
  }
}

static void   ft_prt_ant(t_data *data, int ant_i)
{
  DEBUG ? ft_printf("launching ft_prt_ant ...\n") : DEBUG;
  DEBUG ? ft_printf("ant_i : %d\n", ant_i) : DEBUG;
  DEBUG ? ft_printf("ROOM_IN_PATH_INDEX(%d) : %d\n", ant_i, ROOM_IN_PATH_INDEX(ant_i)) : DEBUG;
  ft_printf("L%d-%s ", ant_i, data->path[ROOM_IN_PATH_INDEX(ant_i)]);
}

int   prt_moving_ant(t_data *data)
{
  int ant_i;

  DEBUG ? ft_printf("launching prt_moving_ant ...\n") : DEBUG;
  ft_init_ant(data);
  while (NOT_ALL_ANT_AT_END)
  {
    DEBUG ? ft_printf("start while\n") : DEBUG;
    DEBUG ? ft_debug_prt_ant(data) : DEBUG;
    ant_i = -1;
    while (++ant_i < data->nb_ant)
      if (ANT_NOT_AT_START(ant_i) && ANT_NOT_AT_END(ant_i))
        ft_prt_ant(data, ant_i);
    DEBUG ? ft_printf("after incr_ant_pos ---\n") : DEBUG;
    ant_i = 0;
    DEBUG ? ft_printf("=============> ant_pos_tab[%d] : %d\n", ant_i, data->ant_pos_tab[ant_i]) : DEBUG;
    DEBUG ? ft_printf("ant_i < data->nb_ant : %d -  ANT_NOT_AT_START(ant_i) : %d - ANT_NOT_AT_END(ant_i) : %d\n",ant_i < data->nb_ant, ANT_NOT_AT_START(ant_i) ,ANT_NOT_AT_END(ant_i)) : DEBUG;
    while (ant_i < data->nb_ant && ANT_NOT_AT_START(ant_i)) //&& ANT_NOT_AT_END(ant_i))
    {
      ant_i++;
      DEBUG ? ft_printf("=============> inside_while\n") : DEBUG;
    }
    DEBUG ? ft_printf("============> ant_i : %d\n", ant_i) : DEBUG;
    if (ant_i < data->nb_ant)
    {
      data->ant_pos_tab[ant_i]++;
      ft_prt_ant(data, ant_i);
      ft_printf("\n");
      DEBUG ? ft_printf("ant_pos_tab[0] : %d\n", data->ant_pos_tab[0]) : DEBUG;
    }
    incr_ant_pos(data);
    DEBUG ? ft_printf("end while\n") : DEBUG;
    DEBUG ? ft_debug_prt_ant(data) : DEBUG;
  }
  return (SUCCESS);
}
