#include "paraser.h"
#include <string.h>
#include <stdlib.h>

char* translate(char c)
{
    switch (c) {
        case '>':
            return "p++;\n";
        case '<':
            return "p--;\n";
        case '+':
            return "*p = *p + 1;\n";
        case '-':
            return "*p = *p - 1;\n";
        case '.':
            return "putchar(*p);\n";
        case ',':
            return "*p=getchar();\n";
        case '[':
            return "while(*p){\n";
        case ']':
            return "}\n";
        default:
            return "";
    }
}

void paraser(char* content, char** c_lang) {

    long length = strlen(content);

    *c_lang = (char*)malloc(512*sizeof(char));
    memset(*c_lang, 0, sizeof(char)*512);
    strcat(*c_lang, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nint main(void){\n\tchar* p = (char*)malloc(sizeof(char)*2048);\nmemset(p, 0, sizeof(char)*2048);\n");

    for (int i = 0; i <= length; ++i) {
        char* translate_temp = translate(content[i]);
        *c_lang = (char*)realloc((char*)*c_lang, (2 + strlen(*c_lang) + strlen(translate_temp))*sizeof(char));
        strcat(*c_lang, translate_temp);
        translate_temp = "";
    }
    *c_lang = (char*)realloc((char*)*c_lang, (2 + strlen(*c_lang) + strlen("return 0;\n}")*sizeof(char)));
    strcat(*c_lang, "return 0;\n}");
#ifdef DEBUG
	printf("after adding new sentence, c_lang is: %s\n\n", *c_lang);
#endif
    return;
}
