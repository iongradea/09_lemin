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
// SUCCESS already defined in gnl equals to 2
# define FAIL 0
# define NOT_FOUND -1
# define ERROR -1
# define UNDEFINED -1

// errors printing
# define PRT_ERROR (write(1, "ERROR\n", 6))
# define PRT_ERROR_DBG (write(1, "here\n", 5))

// line types
# define ANT 1
# define ROOM 2
# define TUBE 3
# define COMMENT 4
# define CMD 5

// tube in map structure
# define TUBE_LINK 1
# define NO_TUBE_LINK 0

// debug
# define DEBUG FALSE
# define DEBUG_MAIN TRUE

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
# define TUBE_ALREADY_SAVED (data->map != NULL && data->map[INDEX_TAB0][INDEX_TAB1] == TUBE_LINK)

// save_line
# define IS_FIRST_LINE (data->lines_in == NULL)

// parser
# define IS_FIRST_ROOM (data->room == NULL)
# define IS_START_ROOM (flag->st_parser == TRUE)
# define IS_END_ROOM (flag->end_parser == TRUE)
# define IS_COMMENT_PARSE (flag->line_type == COMMENT)
# define IS_CMD_PARSE (flag->line_type == CMD)
# define IS_ANT_PARSE (flag->line_type == ANT)
# define IS_ROOM_PARSE (flag->line_type == ROOM)
# define IS_TUBE_PARSE (flag->line_type == TUBE)
# define IS_FIRST_TUBE (data->map == NULL)

// djikstra
# define INDEX_TAB(room) (ft_index_room(data, room))
# define INDEX_TAB_START (INDEX_TAB(data->namestart))
# define INDEX_TAB_END (INDEX_TAB(data->nameend))
# define DIST_SET(i) (data->dist[i] != UNDEFINED)
# define IS_NOT_PART_SPTSET(i) (data->spt_set[i] == FALSE)
# define DIST_SMALLER(i, min_i) (data->dist[i] < data->dist[min_i])
# define NO_POSSIBLE_PATH (min_i == UNDEFINED)
# define END_NOT_PART_SPTSET (data->spt_set[INDEX_TAB(data->nameend)] == FALSE)
# define TUBE_EXIST(index, i) (data->map[index][i] == TUBE_LINK)
# define DIST_UNDEFINED (data->dist[i] == UNDEFINED)
# define DIST_GREATER_INDEX_AND_ONE (data->dist[i] > data->dist[index] + 1)
# define FIRST_LOOP_DJIKSTRA (data->spt_set[INDEX_TAB_START] == FALSE)

// create_rev_path
# define INIT_BY_FINDING_FIRST_VALUE (min_i == UNDEFINED && data->map[INDEX_TAB(node_i)][i] == TUBE_LINK)
# define FIND_SMALLEST_DIST (min_i != UNDEFINED && data->dist[i] < data->dist[min_i])
# define WHILE_START_NODE_NOT_REACHED (min_i != INDEX_TAB_START)

// ft_print_out
# define START_PATH_I 0
# define END_PATH_I (ft_arrlen(data->path) - 1)
# define ANT_NOT_AT_START(i) (data->ant_pos_tab[i] != START_PATH_I)
# define ANT_NOT_AT_END(i) (data->ant_pos_tab[i] != END_PATH_I)
# define NOT_ALL_ANT_AT_END (ch_all_ant_end(data) == FALSE)
# define ROOM_IN_PATH_INDEX(ant_i) (data->ant_pos_tab[ant_i])

// other libraries
#include "../libft/inc/libft.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/get_next_line.h"

/*
details data struct :
- st_cmd : used to count the nb of start cmd => should be 1 at the end
- end_cmd : as above
- lines_in : saves all input lines for printing
- ant_tab : stores the index of the rev path where the ant is in
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
  char **path;
  int  *ant_pos_tab;
}             t_data;

/*
details flag struct :
- process : used to identify whether checking ANT, ROOM or TUBE because they
follow each other / to check errors by check_line
- st_end_flg : used to identify whether the line before was start or end cmd
/ used to check errors by check_line
- line_type : used to identify which line type it is / set in check_line and
used in parse_data
*/
typedef struct s_flag
{
  int  process;
  int  st_end_flg;
  int  line_type;
  int  st_parser;
  int  end_parser;
}              t_flag;

// check errors functions
int		check_line(t_data *data, char *line, t_flag *flag);
void   save_line(t_data *data, char *line);

// parse functions
int   parse_data(t_data *data, char *line, t_flag *flag);

// djikstra functions
int     djikstra(t_data *data);

// create_rev_path
int   create_path(t_data *data);

// print_out
int   prt_moving_ant(t_data *data);

// free functions
void  ft_free_tab(char **tab);
void  ft_free_tab_int(int **tab);

// annex functions
int   ft_tube(char **tab, t_flag *flag);
int   ft_index_room(t_data *data, char *room);
void   ft_ch_st_end_count(t_data *data);
int   parse_st_end_room(t_data *data, char *line, t_flag *flag);
int  ft_set_flag(char *line, t_flag *flag);

// debug functions
void    ft_prt_tab(char **tab);
void    ft_print_tab_int(int **tab);
void  ft_print_djikstra(t_data *data);
void  ft_prt_rev_path(t_data *data);
void  ft_debug_prt_ant(t_data *data);

#endif
