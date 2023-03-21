#include "paraser.h"
#include <string.h>

char* translate(char c)
{
    switch (c) {
        case '>':
            return "p++;";
        case '<':
            return "p--;";
        case '+':
            return "*p = *p + 1;";
        case '-':
            return "*p = *p - 1;";
        case '.':
            return "putchar(*p);";
        case ',':
            return "*p=getchar();";
        case '[':
            return "while(*p){";
        case ']':
            return "}";
        default:
            return "";
    }
}

void paraser(char* content, char* c_lang) {
#ifdef DEBUG
	printf("calc the length of content....\n");
#endif
    long length = strlen(content);
#ifdef DEBUG
	printf("content has length of: %ld\n", length);
#endif
    c_lang = (char*)malloc(512*sizeof(char));
    c_lang = "#include <stdio.h>\n#include<stdlib.h>\nint main(void){\n";
#ifdef DEBUG
	printf("init c_lang to:\n %s\n", c_lang);
#endif
    for (int i = 0; i <= length; ++i) {
#ifdef DEBUG
	printf("reading char is: %c\n", content[i]);
#endif
        char* translate_temp = translate(content[i]);
#ifdef DEBUG
	printf("after translation it become: %s\n", translate_temp);
#endif
        c_lang = (char*)realloc(c_lang, (2 + strlen(c_lang) + strlen(translate_temp))*sizeof(char));
        strcat(c_lang, translate_temp);
#ifdef DEBUG
	printf("after adding new sentence, c_lang is: %s\n\n", c_lang);
#endif
        translate_temp = "";
    }
    c_lang = (char*)realloc(c_lang, (2 + strlen(c_lang) + strlen("return 0;\n}")*sizeof(char)));
    strcat(c_lang, "return 0;\n}");
    return;
}
