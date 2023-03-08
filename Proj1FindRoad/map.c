/*-------------------------------------------
* File name: map.c
* Author: Jingzhe Ni
* brief: 实现了地图输入输出，获取指定位置的地图要素，位置移动等函数
---------------------------------------------*/

#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
/*
 @ param: None
 @ return: None
 @ brief: 读入地图
*/
void Init_Map() {
	int row, col;
	scanf("%d %d", &row, &col);
	getchar();
	map.row = row;
	map.col = col;
	map.map_array = (char*)malloc(map.row * map.col * sizeof(char));
	memset(map.map_array, ' ', map.row * map.col * sizeof(char));
	for (int i = 0; i < map.row; i++) {
		for (int j = 0; j < map.col; j++)
				scanf("%c", &(map.map_array[i * map.col + j]));
		getchar();
	}
		
}

/*
 @ param: Position_t pos
 @ return: int
 @ brief: 返回给定位置上的地图要素(START/ROAD/WALL/FINISH/FOOTPRINT/WRONGWAY)
*/
int What_Is(Position_t pos) {
	if (pos.y >= map.row || pos.y < 0 || pos.x >= map.col || pos.x < 0)
		return VOID;
	switch (map.map_array[pos.y * map.col + pos.x]) {
		case '$': return START;
		case ' ': return ROAD;
		case '#': return WALL;
		case '&': return FINISH;
		case '*': return FOOTPRINT;
		case 'x': return WRONGWAY;
	}
}

/*
 @ param: Position_t pos, int direction
 @ return: Position_t
 @ brief: 返回给定位置向direction移动一格后的位置结构体
*/
Position_t Get_Neigbor(Position_t pos, int direction) {
	Position_t temp_pos = pos;
	switch (direction) {
		case LEFT: {
			temp_pos.x -= 1; break;
		}
		case RIGHT: {
			temp_pos.x += 1; break;
		}
		case UP: {
			temp_pos.y -= 1; break;
		}
		case DOWN: {
			temp_pos.y += 1; break;
		}
	}

	return temp_pos;
}

/*
 @ param: Position_t pos
 @ return: None
 @ brief: 在map的给定位置上绘制足迹('*')
*/
void Set_Footprint(Position_t pos) {
	map.map_array[pos.y * map.col + pos.x] = '*';
}

/*
 @ param: Position_t pos
 @ return: None
 @ brief: 在map的给定位置上绘制错路标记('x')
*/
void Mark_Wrong_Way(Position_t pos) {
	map.map_array[pos.y * map.col + pos.x] = 'x';
}

/*
 @ param: None
 @ return: None
 @ brief: 打印只包含足迹的地图
*/
void Print_Path_On_Map() {
	printf("\nSolution:\n");
	for (int i = 0; i < map.col * map.row; i++) {
		printf("%c", map.map_array[i] == 'x' ? ' ' : map.map_array[i]);
		if ((i+1) % map.col == 0)
			printf("\n");
	}
	//printf("%c", map.map_array[map.col * map.row - 1]);
	return;
}

#ifdef DEBUG
/*
 @ param: None
 @ return: None
 @ brief: 打印全部的地图，包括错路标记、足迹等
*/
void Print_Map() {
	printf("\n\n");
	for (int i = 0; i < map.col * map.row; i++) {
		printf("%c", map.map_array[i]);
		if ((i+1) % map.col == 0)
			printf("\n");
	}
	//printf("%c", map.map_array[map.col * map.row - 1]);
	return;
}

#endif
