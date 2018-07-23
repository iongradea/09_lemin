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

static void    save_first_line(t_data *data, char *line)
{
  if (!(data->lines_in = (char**)malloc(sizeof(char*) * 2)))
    exit(0);
  if (!(data->lines_in[0] = ft_strdup(line)))
    exit(0);
  data->lines_in[1] = NULL;
}

void   save_line(t_data *data, char *line)
{
  char  **tmp;
  int   i;

  if (IS_FIRST_LINE)
    save_first_line(data, line);
  else
  {
    if (!(tmp = (char**)malloc(sizeof(char*) * (ft_arrlen(data->lines_in) + 2))))
      exit(0);
    i = -1;
    while (data->lines_in[++i])
      if (!(tmp[i] = ft_strdup(data->lines_in[i])))
        exit(0);
    if (!(tmp[i] = ft_strdup(line)))
      exit(0);
    tmp[i + 1] = NULL;
    ft_free_tab(data->lines_in);
    data->lines_in = tmp;
  }
}
