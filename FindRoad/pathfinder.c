/*-------------------------------------------
* File name: pathfinder.c
* Author: Jingzhe Ni
* brief: 实现了初始化Path_Finder的函数和回溯寻路功能的函数
---------------------------------------------*/
#include "pathfinder.h"
#include <stdlib.h>
#include <stdio.h>

extern Position_t current_position;
extern Map_t map;
int found_solution = 0;
int last_direction = 0;

void Init_Finder() {
	current_position.x = 0;
	current_position.y = 0;

	//将当前位置设置为起点
	for (int i = 0; i < map.col * map.row; i++) {
		if (map.map_array[i] == '$') {
			current_position.x = i % map.col;
			current_position.y = i / map.col;
		}
	}
}

void Find_Path() {
	for (int direction = UP; direction <= DOWN; direction++)
		if (What_Is(Get_Neigbor(&current_position, direction)) == FINISH) {		
			found_solution = 1;
			return;
		}

	int last_direction_ = last_direction;

	if (What_Is(Get_Neigbor(&current_position, RIGHT)) == ROAD && !found_solution) {
		current_position = Get_Neigbor(&current_position, RIGHT);
		Set_Footprint(&current_position);
		last_direction = RIGHT;
#ifdef DEBUG
		Print_Map();
#endif
		Find_Path(map);
	}
	if (What_Is(Get_Neigbor(&current_position, DOWN)) == ROAD && !found_solution) {
		current_position = Get_Neigbor(&current_position, DOWN);
		Set_Footprint(&current_position);
#ifdef DEBUG
		Print_Map();
#endif
		last_direction = DOWN;
		Find_Path(map);
	}
	if (What_Is(Get_Neigbor(&current_position, UP)) == ROAD && !found_solution) {
		current_position = Get_Neigbor(&current_position, UP);
		Set_Footprint(&current_position);
#ifdef DEBUG
		Print_Map();
#endif
		last_direction = UP;
		Find_Path(map);
	}
	if (What_Is(Get_Neigbor(&current_position, LEFT)) == ROAD && !found_solution) {
		current_position = Get_Neigbor(&current_position, LEFT);
		Set_Footprint(&current_position);
#ifdef DEBUG
		Print_Map();
#endif
		last_direction = LEFT;
		Find_Path(map);
	}

	if (found_solution)
		return;
	
	if (What_Is(current_position) == START && last_direction_ != 0 && !found_solution) {
#ifdef DEBUG
		printf("Step back to Start, no solution!\n");
#endif
		return;
	}
		

	if (last_direction_ != 0) {
		Mark_Wrong_Way(&current_position);
		current_position = Get_Neigbor(&current_position, 23-last_direction_);	

#ifdef DEBUG
		printf("Marked one place as wrong way!\n");
		Print_Map();
#endif
		return;
	}
	

	return;
}