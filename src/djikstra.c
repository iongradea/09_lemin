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
  ft_printf("namestart : %s\n", data->namestart);
  ft_printf("nameend : %s\n", data->nameend);
  data->spt_set[INDEX_TAB_START] = FALSE;
  data->dist[INDEX_TAB_START] = 0;
  return (SUCCESS);
}

static int  min_dist_index(t_data *data)
{
  int i;
  int min_i;

  i = -1;
  min_i = UNDEFINED;
  ft_printf("launching min_dist_index ...\n");
  if (FIRST_LOOP_DJIKSTRA)
  {
    data->spt_set[INDEX_TAB_START] = TRUE;
    ft_printf("min_i : %d - namestart : %s\n", INDEX_TAB_START, data->namestart);
    return (INDEX_TAB_START);
  }
  while (++i < data->nb_room)
  {
    if (DIST_SET(i) && IS_NOT_PART_SPTSET(i))
      min_i = i;
  }
  ft_printf("min_i : %d\n", min_i);
  /*
  ft_printf("xxx\n");
  if (NO_POSSIBLE_PATH)
    exit(PRT_ERROR);*/
  i = -1;
  while (++i < data->nb_room)
  {
    if (DIST_SET(i) && IS_NOT_PART_SPTSET(i) && DIST_SMALLER(i, min_i))
      min_i = i;
  }
  data->spt_set[min_i] = TRUE;
  ft_printf("min_i : %d\n", min_i);
  return (min_i);
}

int     djikstra(t_data *data)
{
  int index;
  int i;

  ft_init_djikstra(data);
  while (END_NOT_PART_SPTSET)
  {
    index = min_dist_index(data);
    ft_printf("index : %d\n", index);
    i = -1;
    while (++i < data->nb_room)
    {
      if (TUBE_EXIST(index, i) && IS_NOT_PART_SPTSET(i))
      {
        ft_printf("tube_exist - bot sptset\n");
        if (DIST_UNDEFINED || DIST_GREATER_INDEX_AND_ONE)
          data->dist[i] = data->dist[index] + 1;
      }
      ft_print_djikstra(data);
    }
  }
  return (SUCCESS);
}
