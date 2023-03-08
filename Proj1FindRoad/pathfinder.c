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

#ifdef DEBUG
int depth = 1;
#endif

/*
 @ param: None
 @ return: None
 @ brief: 初始化寻路者，将当前位置设置为起点坐标
*/
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

/*
 @ param: None
 @ return: None
 @ brief: 回溯算法寻路实现
*/
void Find_Path() {
#ifdef DEBUG
	depth++;
	printf("\nReached %d layers\n", depth);
#endif
	//先找四个方向的邻居格子里有没有终点
	for (int direction = UP; direction <= DOWN; direction++)
		if (What_Is(Get_Neigbor(current_position, direction)) == FINISH) {		
			//有的话就标记找到方案
			found_solution = 1;
			//返回上一层
			return;
		}

	//没有找到终点，那先记录上一步是怎么过来的（上一步的探路方向），为可能的回溯做准备
	int last_direction_ = last_direction;

	//判断四个方向能不能走，能走就走，并更新全局探路方向以传递到下一层
	if (What_Is(Get_Neigbor(current_position, RIGHT)) == ROAD && !found_solution) {
		//更新位置
		current_position = Get_Neigbor(current_position, RIGHT);
		//绘制足迹
		Set_Footprint(current_position);
		//更新探路方向
		last_direction = RIGHT;
#ifdef DEBUG
		Print_Map();
#endif
		//进入下一层
		Find_Path(map);
	}
	if (What_Is(Get_Neigbor(current_position, DOWN)) == ROAD && !found_solution) {
		current_position = Get_Neigbor(current_position, DOWN);
		Set_Footprint(current_position);
#ifdef DEBUG
		Print_Map();
#endif
		last_direction = DOWN;
		Find_Path(map);
	}
	if (What_Is(Get_Neigbor(current_position, UP)) == ROAD && !found_solution) {
		current_position = Get_Neigbor(current_position, UP);
		Set_Footprint(current_position);
#ifdef DEBUG
		Print_Map();
#endif
		last_direction = UP;
		Find_Path(map);
	}
	if (What_Is(Get_Neigbor(current_position, LEFT)) == ROAD && !found_solution) {
		current_position = Get_Neigbor(current_position, LEFT);
		Set_Footprint(current_position);
#ifdef DEBUG
		Print_Map();
#endif
		last_direction = LEFT;
		Find_Path(map);
	}

	//如果四个方向都走不了了就会到这里
	//判断是不是找到了方案，找到了那就退出到上一层
	if (found_solution)
		return;
	
	//到这里肯定是没找到方案了
	//那看看是不是在非第一步（last_direction != 0）但是到达了起点
	if (What_Is(current_position) == START && last_direction_ != 0 && !found_solution) {
		//是的话就说明已经退到无路可退了，那肯定无解，返回
#ifdef DEBUG
		printf("Step back to Start, no solution!\n");
#endif
		return;
	}
		
	//到这里说明既没有找到方案也没有无路可退，那就说明是进入了死胡同
	if (last_direction_ != 0) {
		//标记当前的足迹是不能到达终点的
		Mark_Wrong_Way(current_position);
		//利用23 - direction就是相反方向的性质返回上一步的格子
		current_position = Get_Neigbor(current_position, 23-last_direction_);	

#ifdef DEBUG
		printf("Marked one place as wrong way!\n");
		Print_Map();
#endif
		//返回上一层（上一层可能会换方向探路可能继续回退）
		return;
	}
	

	return;
}