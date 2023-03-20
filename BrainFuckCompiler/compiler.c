#include "compiler.h"
#include "paraser.h"
#include <stdlib.h>
#include <string.h>

/*---------------------Private Functions-------------------------*/
char* Read_Source_File(const char* path){
	FILE* source_file = fopen(path, "r");
	if (source_file == NULL) {
		perror("CANNOT OPEN FILE! PLEASE CHAECK YOUR PATH!");
		return "";
	}
	fseek(source_file, 0L, SEEK_END);
	long file_size = ftell(source_file);
	char* content = (char*)malloc(sizeof(char)*file_size);
	fseek(source_file, 0, SEEK_SET);
	content = fread(content, file_size, 1, source_file);
	if (content == 0) {
		perror("AN EMPTY FILE! NOTHING TO BE COMPILE");
		return "";
	}
#ifdef DEBUG
	printf("content is : %s\n", content);
#endif
	fclose(source_file);
	return content;
}

int Print_C_To_File(const char* path, const char* content){
	FILE* middle_file = NULL;
	middle_file = fopen(path, "w");
	if (middle_file == NULL) {
		perror("FAILED TRANSLATING BF TO C!");
		return -1;
	}
	fprintf(middle_file, "%s", content);
	return 1;
}

int Generate_Excutable(const char* mid_path, const char* target_name){

	system(strcat("gcc ", strcat(mid_path, strcat("-o ", target_name))));
	
	return 1;
}
/*--------------------------Public Function---------------------------*/
int Compile(const char* src, const char* mid, const char* tar) {
	char* content = Read_Source_File(src);
	if (strcmp(content, "")) {
#ifdef DEBUG
		printf("input a wrong path of source");
#endif
		return -1;
	}
	char* c_lang = paraser(content);
	if (Print_C_To_File(mid, c_lang) == -1) {
		return -1;
	}
	Generate_Excutable(mid, tar);
	return 0;
}
