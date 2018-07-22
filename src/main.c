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

static void  ft_init_data(t_data *data)
{
  data->st_cmd = 0;
  data->end_cmd = 0;
  data->st_end_flg = FALSE;
  data->lines_in = NULL;
  data->nb_ant = 0;
  data->nb_room = 0;
  data->nb_tube = 0;
  data->nameend = NULL;
  data->nameend = NULL;
  data->map = NULL;
  data->room = NULL;
  data->dist = NULL;
  data->spt_set = NULL;
}

int   main(void)
{
	char		*line;
	t_data	data;
  int     flag;

	ft_init_data(&data);
  flag = ANT;
	while (get_next_line(0, &line) > 0)
	{
		check_line(&data, line, &flag);
	}
  ft_printf("end main\n");
  ft_ch_st_end_nb(&data);
  return (0);
}
