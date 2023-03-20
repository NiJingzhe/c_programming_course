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

char* paraser(char* content) {
    long long length = strlen(content);
    char* c_lang = "#include <stdio.h>\n#include<stdlib.h>\nint main(void){\n";

    for (int i = 0; i <= length; ++i) {
        char* translate_temp = translate(content[i]);
        c_lang = (char*)realloc(c_lang, (2 + strlen(c_lang) + strlen(translate_temp))*sizeof(char));
        strcat(c_lang, translate_temp);
        translate_temp = "";
    }
    strcat(c_lang, "return 0;\n}");
    return c_lang;
}