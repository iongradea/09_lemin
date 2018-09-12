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

static int  ft_init_djikstra(t_data *data)
{
  int i;

  DEBUG ? ft_printf("launching ft_init_djikstra ...\n") : DEBUG;
  i = -1;
  if (!(data->dist = (int*)malloc(sizeof(int) * data->nb_room)))
    exit(0);
  if (!(data->spt_set = (int*)malloc(sizeof(int) * data->nb_room)))
    exit(0);
  while (++i < data->nb_room)
  {
    data->dist[i] = UNDEFINED;
    data->spt_set[i] = FALSE;
  }
  DEBUG ? ft_printf("namestart : %s\n", data->namestart) : DEBUG;
  DEBUG ? ft_printf("nameend : %s\n", data->nameend) : DEBUG;
  data->spt_set[INDEX_TAB_START] = FALSE;
  data->dist[INDEX_TAB_START] = 0;
  DEBUG_MAIN ? ft_print_djikstra(data) : DEBUG_MAIN;
  return (SUCCESS);
}

static int  min_dist_index(t_data *data)
{
  int i;
  int min_i;

  i = -1;
  min_i = UNDEFINED;
  DEBUG ? ft_printf("launching min_dist_index ...\n") : DEBUG;
  if (FIRST_LOOP_DJIKSTRA)
  {
    data->spt_set[INDEX_TAB_START] = TRUE;
    DEBUG ? ft_printf("min_i : %d - namestart : %s\n", INDEX_TAB_START, data->namestart) : DEBUG;
    return (INDEX_TAB_START);
  }
  while (++i < data->nb_room)
  {
    if (DIST_SET(i) && IS_NOT_PART_SPTSET(i))
      min_i = i;
  }
  DEBUG ? ft_printf("min_i : %d\n", min_i) : DEBUG;
  DEBUG ? ft_printf("check no possible path\n") : DEBUG;
  if (NO_POSSIBLE_PATH)
    exit(PRT_ERROR);
  i = -1;
  while (++i < data->nb_room)
  {
    if (DIST_SET(i) && IS_NOT_PART_SPTSET(i) && DIST_SMALLER(i, min_i))
      min_i = i;
  }
  data->spt_set[min_i] = TRUE;
  DEBUG ? ft_printf("min_i : %d\n", min_i) : DEBUG;
  return (min_i);
}

int     djikstra(t_data *data)
{
  int index;
  int i;

  ft_init_djikstra(data);
  DEBUG ? ft_printf("launching djikstra ...") : DEBUG;
  while (END_NOT_PART_SPTSET)
  {
    index = min_dist_index(data);
    DEBUG ? ft_printf("index : %d\n", index) : DEBUG;
    i = -1;
    while (++i < data->nb_room)
    {
      if (TUBE_EXIST(index, i) && IS_NOT_PART_SPTSET(i))
      {
        DEBUG ? ft_printf("tube_exist - bot sptset\n") : DEBUG;
        if (DIST_UNDEFINED || DIST_GREATER_INDEX_AND_ONE)
          data->dist[i] = data->dist[index] + 1;
      }
      DEBUG ? ft_print_djikstra(data) : DEBUG;
    }
  }
  return (SUCCESS);
}
