#include "pathfinder.h"
#include "map.h"
#include <stdio.h>

extern int found_solution;

int main() {
	Init_Map();
	Init_Finder();
	Find_Path();
	if (found_solution)
		Print_Path_On_Map();
	else
		printf("No Solution");
	return 0;
}