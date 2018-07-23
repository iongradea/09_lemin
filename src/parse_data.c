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

static int   parse_st_end_room(t_data *data, char *line, t_flag *flag)
{
  if (IS_START_ROOM)
  {
    if (!(data->namestart = ft_strdup(line)))
      exit(0);
    flag->st_parser = FALSE;
  }
  else if (IS_END_ROOM)
  {
    if (!(data->nameend = ft_strdup(line)))
      exit(0);
    flag->end_parser = FALSE;
  }
  return (SUCCESS);
}

static int   parse_first_room(t_data *data, char *line)
{
  char  **tab;

  tab = ft_strsplit_c(line, ' ');
  ft_printf("parse_first_room\n");
  if (!(data->room = (char**)malloc(sizeof(char*) * 2)))
    exit(0);
  if (!(data->room[0] = ft_strdup(tab[0])))
    exit(0);
  ft_free_tab(tab);
  data->room[1] = NULL;
  data->nb_room++;
  return (SUCCESS);
}

static int   parse_room(t_data *data, char *line, t_flag *flag)
{
  int i;
  char  **tmp;
  char  **tab;

  tab = ft_strsplit_c(line, ' ');
  ft_printf("parse_room\n");
  if (IS_FIRST_ROOM)
    return (parse_first_room(data, line));
  i = -1;
  if (!(tmp = (char**)malloc(sizeof(char*) * (data->nb_room + 2))))
    exit(0);
  while (++i < data->nb_room)
    if (!(tmp[i] = ft_strdup(data->room[i])))
      exit(0);
  if (!(tmp[i] = ft_strdup(tab[0])))
    exit(0);
  tmp[i + 1] = NULL;
  data->nb_room++;
  ft_free_tab(tab);
  ft_free_tab(data->room);
  if (IS_START_ROOM || IS_END_ROOM)
    parse_st_end_room(data, line, flag);
  data->room = tmp;
  return (SUCCESS);
}

int   parse_data(t_data *data, char *line, t_flag *flag)
{
  ft_printf("parse_data\n");
  if (IS_CMD_PARSE)
    return (ft_set_flag(line, flag));
  if (IS_COMMENT_PARSE)
    return (SUCCESS);
  if (IS_ANT_PARSE)
    return (data->nb_ant = ft_atoi(line));
  if (IS_ROOM_PARSE)
    return (parse_room(data, line, flag));
  /*if (IS_TUBE_PARSE)
    return (parse_tube(data, line));*/
  return (SUCCESS);
}
