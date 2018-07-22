/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igradea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:36:22 by igradea           #+#    #+#             */
/*   Updated: 2017/09/07 04:48:51 by iongradea        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEM_IN_H
# define LEM_IN_H

// vars
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0
# define NOT_FOUND -1
# define ERROR -1
# define UNDEFINED -1

// errors printing
# define PRT_ERROR write(1, "ERROR\n", 6)

// line types
# define ANT 1
# define ROOM 2
# define TUBE 3
# define COMMENT 4
# define COMMAND 5

// line checks
# define IS_EMPTY_LINE *line == '\0'
# define IS_COMMENT *line == '#'
# define IS_COMMAND line[0] == '#' && line[1] == '#'
# define IS_START_CMD ft_strcmp(line, "##start") == 0
# define IS_END_CMD ft_strcmp(line, "##end") == 0
# define START_AND_END_ONLY_ONCE start_cmd == 1 && end_cmd == 1
// ants
# define IS_ZERO ft_strlen(line) == 1 && line[0] == '0'
// ch_room
# define NO_THREE_ELTS ft_arrlen(tab) != 3
# define IT_IS_TUBE ft_arrlen(tab) == 1
# define INCORRECT_ROOM_NAME *tab[0] == 'L'
// ch_tube
# define NO_TWO_ELTS ft_arrlen(tab) != 2
# define THERE_ARE_ROOMS ft_arrlen(data->rooms) != 0
# define TUBE_ALREADY_SAVED data->map != NULL && data->map[INDEX_TAB0][INDEX_TAB1]
# define INDEX_TAB0 ft_index_room(tab[0])
# define INDEX_TAB1 ft_index_room(tab[1])
// check start & end present & only once


#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/get_next_line.h"

typedef struct  s_data
{
  char **lines_in;
  int  nb_ant;
  int  nb_room;
  int  nb_tube;
  char *nameend;
  char *namestart;
  int  **map;
  char **room;
  int  *dist;
  int  *spt_set;
}             t_data;

// check errors functions
int		ft_check_line(t_data *data, char *line, int *flag);

// free functions
void  ft_free_tab(char **tab);

// annex functions
int   ft_tube(char **tab, int *flag);
int   ch_room_saved(t_data *data, char **room);


#endif
