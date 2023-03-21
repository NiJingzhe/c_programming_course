#include "compiler.h"
#include "paraser.h"
#include <stdlib.h>
#include <string.h>

/*---------------------Private Functions-------------------------*/
int Read_Source_File(const char* path, char* content){
	FILE* source_file = fopen(path, "rb+");
	if (source_file == NULL) {
		perror("CANNOT OPEN FILE! PLEASE CHAECK YOUR PATH!");
		return -1;
	}
#ifdef DEBUG
	printf("before fseek\n");
#endif
	fseek(source_file, 0L, SEEK_END);
	long file_size = ftell(source_file);
	content = (char*)malloc(sizeof(char)*file_size);
	fseek(source_file, 0L, SEEK_SET);
#ifdef DEBUG
	printf("after fseek, start to read content\n");
#endif
	fread(content, file_size, 1, source_file);
#ifdef DEBUG
	printf("after reading content\n");
#endif
	if (strcmp(content, "") == 0) {
		perror("AN EMPTY FILE! NOTHING TO BE COMPILE");
		return -1;
	}
#ifdef DEBUG
	printf("content is : ");
	printf("%s\n", content);
#endif
	fclose(source_file);
	return 0;
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
	char* content;
	int result = Read_Source_File(src, content);
#ifdef DEBUG
	printf("out of reading and now content is: %s\n", content);
#endif
	if (result == -1) {
#ifdef DEBUG
		printf("error in reading source file!");
#endif
		return -1;
	}

	char* c_lang;
#ifdef DEBUG
	printf("Enter parasing now!\n");
#endif
	paraser(content, c_lang);
#ifdef DEBUG
	printf("Out of parasing! Print c to middle file!\n");
#endif
	if (Print_C_To_File(mid, c_lang) == -1) {
		return -1;
	}
#ifdef DEBUG
	printf("Generarting exe now!\n");
#endif
	Generate_Excutable(mid, tar);
	return 0;
}
