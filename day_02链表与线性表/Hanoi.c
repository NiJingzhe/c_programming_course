#include "compile_control.h"
#ifdef HANOI
#include<stdio.h>

void move(char A, char C, int n)
{
	printf("No.%d disk: %c->%c\n", n, A, C);
}

void HanoiTower(char A, char B, char C, int n)
{
	if (n == 1)
	{
		move(A, C, n);
	}
	else
	{
		//��n-1��Բ�̴�A��������C���ƶ���B����
		HanoiTower(A, C, B, n - 1);
		//��A�������һ��Բ���ƶ���C����
		move(A, C, n);
		//��n-1��Բ�̴�B��������A���ƶ���C����
		HanoiTower(B, A, C, n - 1);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	//��n��Բ�̴�A��������B���ƶ���C����
	HanoiTower('a', 'b', 'c', n);
	return 0;
}

#endif