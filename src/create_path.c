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

static void  ft_init_path(t_data *data)
{
  int i;

  i = -1;
  DEBUG ? ft_printf("launching ft_init_path ...\n") : DEBUG;
  if (!(data->rev_path = (char**)malloc(sizeof(char*) * (data->nb_room + 1))))
    exit(0);
  while (++i < data->nb_room)
    data->rev_path[i] = NULL;
  if (!(data->rev_path[0] = ft_strdup(data->room[INDEX_TAB_END])))
    exit(0);
}

/*
index_min_dist : returns the min index (in the room tab) of the min distance
from the previous node
*/

static int  index_min_dist(t_data *data, char *node_i)
{
  int i;
  int min_i;

  i = -1;
  min_i = UNDEFINED;
  DEBUG ? ft_printf("launching index_min_dist ...\n") : DEBUG;
  while (++i < data->nb_room)
  {
    if (INIT_BY_FINDING_FIRST_VALUE)
      min_i = i;
    if (FIND_SMALLEST_DIST)
      min_i = i;
  }
  DEBUG ? ft_printf("min_i : %d\n", min_i) : DEBUG;
  return (min_i);
}

int   create_rev_path(t_data *data)
{
  int min_i;
  int len;

  min_i = UNDEFINED;
  DEBUG ? ft_printf("launching create_rev_path ...\n") : DEBUG;
  ft_init_path(data);
  while (WHILE_START_NODE_NOT_REACHED)
  {
    len = ft_arrlen(data->rev_path);
    min_i = index_min_dist(data, data->rev_path[len - 1]);
    if (!(data->rev_path[len] = ft_strdup(data->room[min_i])))
      exit(0);
  }
  return (SUCCESS);
}
