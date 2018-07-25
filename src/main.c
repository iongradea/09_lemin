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
  data->path = NULL;
}

static void   ft_init_flag(t_flag *flag)
{
  flag->process = ANT;
  flag->line_type = UNDEFINED;
  flag->st_end_flg = FALSE;
  flag->st_parser = FALSE;
  flag->end_parser = FALSE;
}

int   main(void)
{
	char		*line;
	t_data	data;
  t_flag  flag;

	ft_init_data(&data);
  ft_init_flag(&flag);
	while (get_next_line(0, &line) > 0)
	{
		check_line(&data, line, &flag);
    save_line(&data, line);
    parse_data(&data, line, &flag);
	}
  ft_ch_st_end_count(&data);
  if (DEBUG_MAIN)
  {
    ft_printf("- END PARSING -\n");
    ft_prt_tab(data.lines_in);
    ft_prt_tab(data.room);
    ft_print_tab_int(data.map);
  }
  djikstra(&data);
  DEBUG_MAIN ? ft_print_djikstra(&data) : DEBUG_MAIN;
  create_path(&data);
  DEBUG_MAIN ? ft_prt_path(&data) : DEBUG_MAIN;
  prt_moving_ant(&data);
  return (0);
}
