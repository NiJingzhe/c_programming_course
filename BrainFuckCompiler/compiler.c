#include "compiler.h"
#include "paraser.h"
#include <stdlib.h>
#include <string.h>

/*---------------------Private Functions-------------------------*/
int Read_Source_File(const char* path, char** content){
	FILE* source_file = fopen(path, "rb+");
	if (source_file == NULL) {
		perror("CANNOT OPEN FILE! PLEASE CHAECK YOUR PATH!");
		return -1;
	}
	fseek(source_file, 0L, SEEK_END);
	long file_size = ftell(source_file);
	*content = (char*)malloc(sizeof(char)*file_size);
	fseek(source_file, 0L, SEEK_SET);
	fread(*content, file_size, 1, source_file);
	if (strcmp(*content, "") == 0) {
		perror("AN EMPTY FILE! NOTHING TO BE COMPILE");
		return -1;
	}
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
	fclose(middle_file);
	return 0;
}

int Generate_Excutable(const char* mid_path, const char* target_name, const char* mode){
	char gcc[4096] = "gcc ";
	char o[2048] = " -o ";
	#ifdef LINUX
	char del[2048] = "rm ";
	#endif
	#ifdef WIN
	char del[2048] = "del ";
	#endif
	char* mid_path_copy = (char*)malloc(sizeof(char)*2048);
	strcpy(mid_path_copy, mid_path);
	system(strcat(gcc, strcat(mid_path_copy, strcat(o, target_name))));
	if (!strcmp(mode, "-km") == 0)
		system(strcat(del, mid_path));
	return 0;
}


/*--------------------------Public Function---------------------------*/
int Compile(const char* src, const char* mid, const char* tar, const char* mode) {
	char* content;
	if (Read_Source_File(src, &content) == -1) {
		return -1;
	}

	char* c_lang;
	printf("Enter parasing now!\n");
	paraser(content, &c_lang);
	printf("Out of parasing! Print c to middle file!\n");
	if (Print_C_To_File(mid, c_lang) == -1) {
		return -1;
	}
	printf("Generarting exe now!\n");
	Generate_Excutable(mid, tar, mode);
	return 0;
}
