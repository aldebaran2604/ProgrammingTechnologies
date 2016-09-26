#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct instruction
{
    char* name;
    int code;
    void (*setName)(struct instruction*, char*);
};

void func_set(struct instruction* i, char* n);

int main(void)
{
    struct instruction* i1 = (struct instruction*) malloc(sizeof(struct instruction));
    i1->name = "MOV";
    i1->code = 1;
    printf("Code: %i",i1->code);
    printf("\n");
    printf("Name: %s",i1->name);
    printf("\n");
     
    i1->setName=&func_set;
    i1->setName(i1,"Que tal!");
    return EXIT_SUCCESS;
}

void func_set(struct instruction* i, char* n)
{
   i->name = n;
   printf("Name: %s",i->name);
   printf("\n");
}
