/*------------------------------------------- 
* File name: map.h
* Author: Jingzhe Ni
* brief: ����������������ͼ��λ�õ������ṹ�壬
		 �����˺͵�ͼ�������ƶ������йصĺ���
---------------------------------------------*/

#ifndef __MAP_H__
#define __MAP_H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <memory.h>
/*-----------------------Macro Definition----------------------*/
#define RELEASE //if you want to run in debug mode, please change RELEASE to DEBUG
                //and you can see more detailed solving process.

//�����˸��ֵ�ͼҪ�أ�����Ӧ�Ա�Եǽ��ȱʧ�����
#define WALL 0
#define ROAD 1
#define VOID 2
#define FINISH 3
#define START 4
#define FOOTPRINT 5
#define WRONGWAY 6

//23 - ���� ���Եõ��෴��������������ڻ�����һ��ʱ������һ���ķ���ȷ�����ݷ���
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

//ʹ�õ���ģʽ������Ψһmapʵ��
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