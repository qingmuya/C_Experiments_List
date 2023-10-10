#ifndef NUMBERCONVERSION_H_INCLUDED
#define NUMBERCONVERSION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct{
    int *base;
    int *top;
    int stacksize;
}SqStack;

void conversion();

void InitStack(SqStack &s);

void push(SqStack &s,int e);

void push2(SqStack &s,char e);

int  pop(SqStack &s);

char pop2 (SqStack &s);

bool StackEmpty(SqStack &s);
#endif // NUMBERCONVERSION_H_INCLUDED
