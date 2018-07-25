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
  if (!(data->path = (char**)malloc(sizeof(char*) * (data->nb_room + 1))))
    exit(0);
  while (++i < data->nb_room)
    data->path[i] = NULL;
  if (!(data->path[0] = ft_strdup(data->room[INDEX_TAB_END])))
    exit(0);
}

static void   ft_rev_path(t_data *data)
{
  char  **tab;
  int   len;
  int   i;
  char  **tmp;

  len = ft_arrlen(data->path);
  i = -1;
  tmp = NULL;
  if (!(tab = (char**)malloc(sizeof(char*) * (len + 1))))
    exit(0);
  while (++i < len)
    if (!(tab[i] = ft_strdup(data->path[len - 1 - i])))
      exit(0);
  tab[i] = NULL;
  tmp = data->path;
  data->path = tab;
  ft_free_tab(tmp);
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

int   create_path(t_data *data)
{
  int min_i;
  int len;

  min_i = UNDEFINED;
  DEBUG ? ft_printf("launching create_rev_path ...\n") : DEBUG;
  ft_init_path(data);
  while (WHILE_START_NODE_NOT_REACHED)
  {
    len = ft_arrlen(data->path);
    min_i = index_min_dist(data, data->path[len - 1]);
    if (!(data->path[len] = ft_strdup(data->room[min_i])))
      exit(0);
  }
  ft_rev_path(data);
  return (SUCCESS);
}
