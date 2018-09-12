# LEMIN

## Launch
`make re`<br/>
`./lem-in < maps/subject-1.map`

## Goal
The lem-in project is composed of ants that need to reach a destination as fast as possible through a graph.<br/>
The goal of the algorithm is to find the shortest path and have the ants reach the destination.<br/>

## Game explanation

The program receives on stdin the following information :<br/>
- ant number<br/>
- rooms (name and coordinates)<br/>
-- ##start and ##end indicates the start and end room<br/>
- links (between the different rooms)<br/>

Example :<br/>
![Alt text](./img/input_data.png?raw=true "Title")

The program parses the difference information, computes the shortest path and prints on stdout the state of each turn (where are the ants located).<br/>

Example 1 :<br/>
![Alt text](./img/ex_1.png?raw=true "Title")

Example 2 : <br/>
![Alt text](./img/ex_2.png?raw=true "Title")

## Data structure

Program data structure is as followed :<br/>
- st_cmd & end_cmd : ...<br/>
- lines_in : all lines saved from stdin<br/>
- nb_ant, nb_room, nb_tube : the respective number for each<br/>
- nameend & namestart : names of start and end room<br/>
- room : lists all the rooms<br/>
-- the room index of the tab above is used for map, list, sptset<br/>
- map : identifies the links between the different rooms<br/>
- dist : computes shortest path to this room using djikstra<br/>
- spt_set : used for dijstra (the set of room already visited)<br/>
- path : the shortest path written with the room names<br/>
- ant_pos_tab : a tab where the index represents the ant and the value the room index visited <br/>

![Alt text](./img/data_structure.png?raw=true "Title")

Check structure :<br/>
This structure is used during the parsing and checking errors at the beginning of the program.<br> 

![Alt text](./img/check_structure.png?raw=true "Title")

To follow the program and debug, there is a DEBUG macro in the include file in ./inc. Setting DEBUG to 1 prints logs on stdout.

## Program architecture

Initialization :<br>
- check lines.c : verify that each line is valid<br>
- save_line.c : save the lines in data->lines_in<br>
- parse_data.c : parsing<br>
Algorithm :<br>
- djikstra.c : find the shortest path algorithm<br>
- create_path.c : create the shortest path in data->path<br>
- print_out.c : prints the different turns when each ant goes through the mesh<br>

![Alt text](./img/file_structure.png?raw=true "Title")


## Strategy
For the sake of simplicity and speed development, the chosen algorithm is djikstra and all ants follow the shortest path. No time throughput optimization has been done.
