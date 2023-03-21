#include "headers/paraser.h"
#include <string.h>
#include <stdlib.h>

char* translate(char c)
{
    switch (c) {
        case '>':
            return "if(cur->next==NULL){cur->next=node(cur);cur=cur->next;}else{cur=cur->next;}\n";
        case '<':
            return "assert(cur->prev);cur=cur->prev;\n";
        case '+':
            return "cur->val+=1;\n";
        case '-':
            return "cur->val-=1;\n";
        case '.':
            return "putchar(cur->val);\n";
        case ',':
            return "cur->val=getchar();\n";
        case '[':
            return "while(cur->val){\n";
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
    strcat(*c_lang, "#include <stdio.h>\n\
                     #include <stdlib.h>\n\
                     #include <string.h>\n\
                     #include <assert.h>\n\
                     typedef struct node {\n\
                        char val; struct node *next, *prev;\n\
                     } Node_t;\n\
                     Node_t* node(Node_t* prev) { Node_t *n=(Node_t*)malloc(sizeof(Node_t)); n->val = 0; n->prev = prev; n->next = NULL; return n; }\n\
                     int main(void){\n\
                        Node_t *cur = node(NULL);\n");
               
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
