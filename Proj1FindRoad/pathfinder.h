/*-------------------------------------------
* File name: pathfinder.h
* Author: Jingzhe Ni
* brief: 声明了和回溯寻路相关的函数
---------------------------------------------*/
#ifndef __PATHFINDER_H__
#define __PATHFINDER_H__

#include "map.h"

//单例模式，创建唯一当前位置实例
Position_t current_position;

void Init_Finder();
void Find_Path();

#endif