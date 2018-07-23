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
// SUCCESS already defined in gnl
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
# define CMD 5

// check_line
# define IS_START_CMD (ft_strcmp(line, "##start") == 0)
# define IS_END_CMD (ft_strcmp(line, "##end") == 0)
# define IS_EMPTY_LINE (*line == '\0')
# define IS_COMMENT (*line == '#')
// ants
# define IS_ZERO (ft_strlen(line) == 1 && line[0] == '0')
// ch_room
# define NO_THREE_ELTS (ft_arrlen(tab) != 3)
# define IS_TUBE (ft_arrlen(tab) == 1)
# define INCORRECT_ROOM_NAME (*tab[0] == 'L')
# define ROOM_ALREADY_SAVED (data->room != NULL && ft_arrlen(data->room) != 0 && ft_index_room(data, tab[0]) != NOT_FOUND)
// ch_tube
# define NO_TWO_ELTS (ft_arrlen(tab) != 2)
# define THERE_ARE_ROOMS (data->room != NULL && ft_arrlen(data->room) != 0)
# define INDEX_TAB0 (ft_index_room(data, tab[0]))
# define INDEX_TAB1 (ft_index_room(data, tab[1]))
# define TUBE_ALREADY_SAVED (data->map != NULL && data->map[INDEX_TAB0][INDEX_TAB1])

// save_line
# define IS_FIRST_LINE (data->lines_in == NULL)

#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/get_next_line.h"


/*
details structure :
- st_cmd : used to count the nb of start cmd => should be 1 at the end
- end_cmd : as above
- lines_in : saves all input lines for printing
*/
typedef struct  s_data
{
  int  st_cmd;
  int  end_cmd;
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

typedef struct s_flag
{
  int  process;
  int  line_type;
  int  st_end_flg;
}              t_flag;

// check errors functions
int		check_line(t_data *data, char *line, t_flag *flag);
void   save_line(t_data *data, char *line);


// free functions
void  ft_free_tab(char **tab);

// annex functions
int   ft_tube(char **tab, t_flag *flag);
int   ft_index_room(t_data *data, char *room);
void   ft_ch_st_end_count(t_data *data);

// debug functions
void    ft_prt_tab(char **tab);

#endif
