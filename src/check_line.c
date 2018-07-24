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

/*
check ants : not a digit
*/
static int		ch_nb_ants(char *line, t_flag *flag)
{
	int		i;

	i = 0;
  DEBUG ? ft_printf("launching ch_ant ...\n") : DEBUG;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) || IS_ZERO)
			exit(PRT_ERROR);
		i++;
	}
	flag->process = ROOM;
	flag->line_type = ANT;
	return (SUCCESS);
}

/*
checks room :
- not a tube
- not 3 elts or room saved already
- incorrect room name
- room coordinates are not digits
*/
static int    ch_room(t_data *data, char *line, t_flag *flag)
{
  char  **tab;
  int   i;

  tab = ft_strsplit_c(line, ' ');
  DEBUG ? ft_printf("launching ch_room ...\n") : DEBUG;
  if (NO_THREE_ELTS && flag->st_end_flg == TRUE)
    exit(PRT_ERROR);
  if (IS_TUBE)
    return (ft_tube(tab, flag));
  if (NO_THREE_ELTS)
    exit(PRT_ERROR);
  if (INCORRECT_ROOM_NAME)
    exit(PRT_ERROR);
  if (ROOM_ALREADY_SAVED)
    exit(PRT_ERROR);
  i = -1;
	while (tab[1][++i])
		if (!ft_isdigit(tab[1][i]))
			exit(PRT_ERROR);
	i = -1;
	while (tab[2][++i])
		if (!ft_isdigit(tab[2][i]))
			exit(PRT_ERROR);
	ft_free_tab(tab);
	flag->line_type = ROOM;
  flag->st_end_flg = FALSE;
  return (SUCCESS);
}

/*
check list :
- 2 elements for tube
- rooms have been saved
- tube rooms presents in room list
- tube is present only once
*/
static int    ch_tube(t_data *data, char *line, t_flag *flag)
{
  char  **tab;

  tab = ft_strsplit_c(line, '-');
  DEBUG ? ft_printf("launching ch_tube ...\n") : DEBUG;
  if (NO_TWO_ELTS)
    exit(PRT_ERROR);
  if (THERE_ARE_ROOMS == FALSE)
    exit(PRT_ERROR);
  if (ft_index_room(data, tab[0]) == NOT_FOUND ||
    ft_index_room(data, tab[1]) == NOT_FOUND)
    exit(PRT_ERROR);
  if (TUBE_ALREADY_SAVED)
    exit(PRT_ERROR);
  ft_free_tab(tab);
	flag->line_type = TUBE;
  return (SUCCESS);
}

static int  ch_st_end(t_data *data, char *line, t_flag *flag)
{
	DEBUG ? ft_printf("launching ch_st_end ...\n") : DEBUG;
  if (IS_START_CMD)
    data->st_cmd++;
  else if (IS_END_CMD)
    data->end_cmd++;
	flag->line_type = CMD;
  flag->st_end_flg = TRUE;
  return (SUCCESS);
}


/*
check errors :
- line is NULL
- empty line
- line starts with ##start or ##end before the ant number or just after a valid
cmd
- checks ant
- check room
- check tube
*/
int				check_line(t_data *data, char *line, t_flag *flag)
{
  static int i = 0;

  DEBUG ? ft_printf("launching check_line ... - i : %d\n", i) : DEBUG;
  i++;
	if (line == NULL)
		exit(PRT_ERROR);
	if (IS_EMPTY_LINE)
		exit(PRT_ERROR);
	if (IS_COMMENT && !IS_START_CMD && !IS_END_CMD)
		return (flag->line_type = COMMENT);
  if ((IS_START_CMD || IS_END_CMD) && (flag->process == ANT || flag->st_end_flg == TRUE))
    exit(PRT_ERROR);
	if (flag->process == ANT)
		return (ch_nb_ants(line, flag));
  if (IS_START_CMD || IS_END_CMD)
    return (ch_st_end(data, line, flag));
	if (flag->process == ROOM)
    ch_room(data, line, flag);
	if (flag->process == TUBE)
		ch_tube(data, line, flag);
	return (SUCCESS);
}
