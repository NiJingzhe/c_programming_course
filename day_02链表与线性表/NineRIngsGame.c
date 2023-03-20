#include "compile_control.h"
#ifdef NINE_RINGS
#include <stdio.h>
#include <memory.h>

//Use 0 to represent Down and 1 is Up
int ring_state[11];

void UpRing(int id);
void DownRing(int id);


int main() {
	int target_num;
	char operate;
	scanf("%d %c", &target_num, &operate);

	int i, finished = 0;
	switch (operate) {
	case 'U': {
		//If we need up ring then we suppose all rings are down at first
		memset(ring_state, 0, sizeof(int) * 11);
		while (!finished) {
			for (i = target_num; i >= 1; i--) {
				UpRing(i);
			}
			for (i = 1; i <= target_num; i++) {
				if (!ring_state[i]) {
					break;
				}
			}
			if (i == target_num + 1) {
				finished = 1;
			}
		}
		break;
	}
	case 'D': {
		//the same as before, suppose all rings are up at first
		memset(ring_state, 1, sizeof(int) * 11);
		while (!finished) {
			for (i = target_num; i >= 1; i--) {
				DownRing(i);
			}
			for (i = 1; i <= target_num; i++) {
				if (ring_state[i]) {
					break;
				}
			}
			if (i == target_num + 1) {
				finished = 1;
			}
		}
		break;
	}
	}
	return 0;
}

void UpRing(int id) {

	if (ring_state[id])
		return;

	if (id == 1) {
		printf("1: U\n");
		ring_state[1] = 1;

		return;
	}

	if (id == 2) {
		if (ring_state[1]) {
			printf("2: U\n");
			ring_state[2] = 1;

			return;
		}
		else {
			UpRing(1);
			printf("2: U\n");
			ring_state[2] = 1;

			return;
		}
	}

	int able_to_get_down = 0;
	UpRing(id - 1);
	int i;
	while (!able_to_get_down) {
		for (i = id - 2; i >= 1; i--) {
			DownRing(i);
		}
		for (i = 1; i <= id - 2; i++) {
			if (ring_state[i])
				break;
		}
		if (i == id - 1) {
			able_to_get_down = 1;
		}
	}


	printf("%d: U\n", id);
	ring_state[id] = 1;


	return;
}

void DownRing(int id) {

	if (!ring_state[id])
		return;

	if (id == 1) {
		printf("1: D\n");
		ring_state[1] = 0;

		return;
	}

	if (id == 2) {
		if (ring_state[1]) {
			printf("2: D\n");
			ring_state[2] = 0;

			return;
		}
		else {
			UpRing(1);
			printf("2: D\n");
			ring_state[2] = 0;

			return;
		}
	}

	int able_to_get_down = 0;
	UpRing(id - 1);
	int i;
	while (!able_to_get_down) {
		for (i = id - 2; i >= 1; i--) {
			DownRing(i);
		}
		for (i = 1; i <= id - 2; i++) {
			if (ring_state[i])
				break;
		}
		if (i == id - 1) {
			able_to_get_down = 1;
		}
	}

	printf("%d: D\n", id);
	ring_state[id] = 0;

	return;
}

#endif