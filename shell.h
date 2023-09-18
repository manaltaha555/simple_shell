#ifndef SHELL_H
#define SHELL_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
char *_getline(void);
char *_strtok(char *token);
char *_strtok_cp(char *token, int argc);


#endif
