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
static int		ch_nb_ants(char *line, int *flag)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) || IS_ZERO)
			exit(PRT_ERROR);
		i++;
	}
	*flag = ROOM;
	return (SUCCESS);
}

/*
checks room :
- not a tube
- not 3 elts or room saved already
- incorrect room name
- room coordinates are not digits
*/
static int    ch_room(t_data *data, char *line, int *flag)
{
  char  **tab;
  int   i;

  tab = ft_strsplit_c(line, ' ');
  if (IT_IS_TUBE)
    return (ft_tube(tab, flag));
  if (NO_THREE_ELTS || ch_room_saved(data, tab))
    exit(PRT_ERROR);
  if (INCORRECT_ROOM_NAME)
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
  return (SUCCESS);
}

/*
check list :
- 2 elements for tube
- rooms have been saved
- tube rooms presents in room list
- tube is present only once
*/
static int    ch_tube(t_data *data, char *line)
{
  char  **tab;

  tab = ft_strsplit_c(line, '-');
  if (NO_TWO_ELTS)
    exit(PRT_ERROR);
  if (THERE_ARE_ROOMS == FALSE)
    exit(PRT_ERROR);
  if (ft_index_room(data, tab[0]) != NOT_FOUND ||
    ft_index_room(data, tab[1]) != NOT_FOUND)
    exit(PRT_ERROR);
  if (TUBE_ALREADY_SAVED)
    exit(PRT_ERROR);
  ft_free_tab(tab);
  return (SUCCESS);
}

int				check_line(t_data *data, char *line, int *flag)
{
  static int  start_cmd = 0;
  static int  end_cmd = 0;

	if (line == NULL)
		return (FAIL);
	if (IS_EMPTY_LINE)
		return (FAIL);
  if (IS_START_COMMAND)
    start_cmd++;
  if (IS_END_COMMAND)
    end_cmd++;
	if (IS_COMMENT || IS_COMMAND)
		return (COMMENT);
	if (*flag == ANT)
		return (ch_nb_ants(line, flag));
	if (*flag == ROOM)
    ch_room(data, line, flag);
	if (*flag == TUBE)
		ch_tube(data, line);
  if (START_AND_END_ONLY_ONCE == FALSE)
    exit(PRT_ERROR);
	return (SUCCESS);
}
