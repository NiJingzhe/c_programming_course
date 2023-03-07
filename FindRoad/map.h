/*------------------------------------------- 
* File name: map.h
* Author: Jingzhe Ni
* brief: 定义了用于描述地图和位置的两个结构体，
		 声明了和地图操作和移动操作有关的函数
---------------------------------------------*/

#ifndef __MAP_H__
#define __MAP_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <memory.h>
/*-----------------------Macro Definition----------------------*/
#define RELEASE //if you want to run in debug mode, please change RELEASE to DEBUG
                //and you can see more detailed solving process.

//定义了各种地图要素，可以应对边缘墙体缺失的情况
#define WALL 0
#define ROAD 1
#define VOID 2
#define FINISH 3
#define START 4
#define FOOTPRINT 5
#define WRONGWAY 6

//23 - 方向 可以得到相反方向。这个特性用于回溯上一步时根据上一步的方向确定回溯方向
//23 - UP == DOWM, 23 - RIGHT == LEFT
#define UP 10
#define RIGHT 11
#define LEFT 12
#define DOWN 13
/*-----------------------Type definition-----------------------*/
typedef struct {
	int x;
	int y;
}Position_t;

typedef struct {
	int row;
	int col;

	char* map_array;
} Map_t;

//使用单例模式，创建唯一map实例
Map_t map;

/*---------------Public Function Declaration------------------*/
void Init_Map();

int What_Is(Position_t pos);

Position_t Get_Neigbor(Position_t pos, int direction);

void Set_Footprint(Position_t pos);

void Erase_FootPrint(Position_t pos);

void Mark_Wrong_Way(Position_t pos);

void Print_Map();

void Print_Path_On_Map();
#endif