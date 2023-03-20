#include "compiler.h"
#include "paraser.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		char* source_path = (char*)malloc(255 * sizeof(char));
		char* middle_path = (char*)malloc(255 * sizeof(char));
		char* target_path = (char*)malloc(255 * sizeof(char));
		gets(source_path);
		middle_path = "./middle.c";
		gets(target_path);
		Compile(source_path, middle_path, target_path);
		return 0;
	}
	if (argc == 2) {
		if (strcmp(argv[1], "-h") == 0) {
			printf("BF arguments:\n -h : help\n -s : 指定源文件路径\n -o : 指定输出文件名称\n e.g. BF -s path/to/source -o target.exe");
			return 0;
		}
		else {
			printf("wrong arguments! for detail please type BF -h");
			return 0;
		}
	}

	if (argc == 5) {
		if (strcmp(argv[1], "-s") == 0 && strcmp(argv[3], "-o") == 0) {
			char* source_path = (char*)malloc((strlen(argv[2]) + 1) * sizeof(char));
			char* middle_path = (char*)malloc((strlen(argv[2]) + 1) * sizeof(char));
			char* target_path = (char*)malloc((strlen(argv[4]) + 1) * sizeof(char));
			strcpy(source_path, argv[2]);
			strcpy(middle_path, argv[2]);
			strcpy(target_path, argv[4]);
			int i;
			for (i = strlen(middle_path); middle_path[i] != '/' && middle_path[i] != '\\'; --i);
			middle_path[i+1] = '\0';
			target_path[i+1] = '\0';
			strcat(middle_path, "middle.c");
			//strcat(target_path, argv[4]);
			if (Compile(source_path, middle_path, target_path) < 0) {
				printf("\n\nPLEASE CHECK YOUR ARGUMENTS AND TRY AGAIN.");
				return 0;
			}
			return 0;
		}
		else {
			printf("wrong arguments! for detail please type BF -h");
			return 0;
		}
	}
	else {
		printf("wrong arguments! for detail please type BF -h");
		return 0;
	}
}