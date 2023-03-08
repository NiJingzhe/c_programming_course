/*-------------------------------------------
* File name: pathfinder.c
* Author: Jingzhe Ni
* brief: ʵ���˳�ʼ��Path_Finder�ĺ����ͻ���Ѱ·���ܵĺ���
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
 @ brief: ��ʼ��Ѱ·�ߣ�����ǰλ������Ϊ�������
*/
void Init_Finder() {
	current_position.x = 0;
	current_position.y = 0;

	//����ǰλ������Ϊ���
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
 @ brief: �����㷨Ѱ·ʵ��
*/
void Find_Path() {
#ifdef DEBUG
	depth++;
	printf("\nReached %d layers\n", depth);
#endif
	//�����ĸ�������ھӸ�������û���յ�
	for (int direction = UP; direction <= DOWN; direction++)
		if (What_Is(Get_Neigbor(current_position, direction)) == FINISH) {		
			//�еĻ��ͱ���ҵ�����
			found_solution = 1;
			//������һ��
			return;
		}

	//û���ҵ��յ㣬���ȼ�¼��һ������ô�����ģ���һ����̽·���򣩣�Ϊ���ܵĻ�����׼��
	int last_direction_ = last_direction;

	//�ж��ĸ������ܲ����ߣ����߾��ߣ�������ȫ��̽·�����Դ��ݵ���һ��
	if (What_Is(Get_Neigbor(current_position, RIGHT)) == ROAD && !found_solution) {
		//����λ��
		current_position = Get_Neigbor(current_position, RIGHT);
		//�����㼣
		Set_Footprint(current_position);
		//����̽·����
		last_direction = RIGHT;
#ifdef DEBUG
		Print_Map();
#endif
		//������һ��
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

	//����ĸ������߲����˾ͻᵽ����
	//�ж��ǲ����ҵ��˷������ҵ����Ǿ��˳�����һ��
	if (found_solution)
		return;
	
	//������϶���û�ҵ�������
	//�ǿ����ǲ����ڷǵ�һ����last_direction != 0�����ǵ��������
	if (What_Is(current_position) == START && last_direction_ != 0 && !found_solution) {
		//�ǵĻ���˵���Ѿ��˵���·�����ˣ��ǿ϶��޽⣬����
#ifdef DEBUG
		printf("Step back to Start, no solution!\n");
#endif
		return;
	}
		
	//������˵����û���ҵ�����Ҳû����·���ˣ��Ǿ�˵���ǽ���������ͬ
	if (last_direction_ != 0) {
		//��ǵ�ǰ���㼣�ǲ��ܵ����յ��
		Mark_Wrong_Way(current_position);
		//����23 - direction�����෴��������ʷ�����һ���ĸ���
		current_position = Get_Neigbor(current_position, 23-last_direction_);	

#ifdef DEBUG
		printf("Marked one place as wrong way!\n");
		Print_Map();
#endif
		//������һ�㣨��һ����ܻỻ����̽·���ܼ������ˣ�
		return;
	}
	

	return;
}