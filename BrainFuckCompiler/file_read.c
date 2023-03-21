#include <stdlib.h>
#include <stdio.h>
#include "paraser.h"

int main(){
	FILE* fp = fopen("./test.bf", "rb");
	char* content;

	fseek(fp, 0L, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	content = (char*)malloc(size);
	fread(content, size, 1, fp);
	char* c_lang;
	paraser(content, c_lang);
	printf("%s\n", c_lang);
	return 0;
}
