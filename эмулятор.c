#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//======================================================================

#define MOV 1
#define ADD 2
#define SUB 3
#define MUL 4
#define DIV 5
#define RET 0

//======================================================================

double reg[4] = {0};

//======================================================================

int command_finder(char* str);
int register_finder(char* str);
void mov(char* str);
void add(char* str);
void sub(char* str);
void mul(char* str);
void div(char* str);

int main()
{
    char* str = (char*)calloc(11, sizeof(char));
    while(1)
    {
        scanf("%s", str);
        switch(command_finder(str))
        {
            case MOV:
                mov(str);
                break;
            case ADD:
                add(str);
                break;
            case SUB:
                sub(str);
                break;
            case MUL:
                mul(str);
                break;
            case DIV:
                div(str);
                break;
            case RET:
                free(str);
                return 0;
            default:
                printf("ERROR: undefined command\n");
                break;
        }
    }
    free(str);
    return 0;
}

//======================================================================

int command_finder(char* str)
{
    int command = 10;
    switch (str[0])
    {
        case 'a':
            if (!strcmp(str, "add"))
                command = ADD;
            break;
        case 'd':
            if (!strcmp(str, "div"))
                command = DIV;
            break;
        case 'r':
            if (!strcmp(str, "ret"))
                command = RET;
            break;
        case 's':
            if (!strcmp(str, "sub"))
                command = SUB;
            break;
        case 'm':
            if (!strcmp(str, "mov"))
                command = MOV;
            if (!strcmp(str, "mul"))
                command = MUL;
            break;
        default:
            command = 10;
            break;
    }
    return command;
}

//======================================================================

void mov(char* str)
{
    scanf("%s", str);
    int first_register = register_finder(str);
    scanf("%s", str);
    if (isdigit(str[0]) || str[0] == '-')
    {
        int num = atof(str);
        reg[first_register] = num;
    }
    else
    {
        int second_register = register_finder(str);
        reg[first_register] = reg[second_register];
    }
    for (int i = 0; i < 4; i++)
        printf("%lg ", reg[i]);
    printf("\n");
    return;
}

//======================================================================

void add(char* str)
{
    scanf("%s", str);
    int first_register = register_finder(str);
    scanf("%s", str);
    if (isdigit(str[0]) || str[0] == '-')
    {
        int num = atof(str);
        reg[first_register] = reg[first_register] + num;
    }
    else
    {
        int second_register = register_finder(str);
        reg[first_register] = reg[first_register] + reg[second_register];
    }
    for (int i = 0; i < 4; i++)
        printf("%lg ", reg[i]);
    printf("\n");
    return;
}

//======================================================================

void sub(char* str)
{
    scanf("%s", str);
    int first_register = register_finder(str);
    scanf("%s", str);
    if (isdigit(str[0]) || str[0] == '-')
    {
        int num = atof(str);
        reg[first_register] = reg[first_register] - num;
    }
    else
    {
        int second_register = register_finder(str);
        reg[first_register] = reg[first_register] - reg[second_register];
    }
    for (int i = 0; i < 4; i++)
        printf("%lg ", reg[i]);
    printf("\n");
    return;
}

//======================================================================

void mul(char* str)
{
    scanf("%s", str);
    int first_register = register_finder(str);
    scanf("%s", str);
    if (isdigit(str[0]) || str[0] == '-')
    {
        int num = atof(str);
        reg[first_register] = reg[first_register] * num;
    }
    else
    {
        int second_register = register_finder(str);
        reg[first_register] = reg[first_register] * reg[second_register];
    }
    for (int i = 0; i < 4; i++)
        printf("%lg ", reg[i]);
    printf("\n");
    return;
}

//======================================================================

void div(char* str)
{
    scanf("%s", str);
    int first_register = register_finder(str);
    scanf("%s", str);
    if (isdigit(str[0]) || str[0] == '-')
    {
        int num = atof(str);
        reg[first_register] = reg[first_register] / num;
    }
    else
    {
        int second_register = register_finder(str);
        reg[first_register] = reg[first_register] / reg[second_register];
    }
    for (int i = 0; i < 4; i++)
        printf("%lg ", reg[i]);
    printf("\n");
    return;
}

//======================================================================

int register_finder(char* str)
{
    int register_number = 10;
    switch(str[1])
        {
        case 'a':
            if (!strcmp(str, "eax,"))
                register_number = 0;
            else
                printf("ERROR: you missed ','\n");
            break;
        case 'b':
            if (!strcmp(str, "ebx,"))
                register_number = 1;
            else
                printf("ERROR: you missed ','\n");
            break;
        case 'c':
            if (!strcmp(str, "ecx,"))
                register_number = 2;
            else
                printf("ERROR: you missed ','\n");
            break;
        case 'd':
            if (!strcmp(str, "edx,"))
                register_number = 3;
            else
                printf("ERROR: you missed ','\n");
            break;
        default:
            printf("ERROR: wrong register\n");
            break;
        }
    return register_number;
}







