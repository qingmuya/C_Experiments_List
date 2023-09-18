#ifndef LINK_LIST_H_INCLUDED
#define LINK_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

//定义顺序表
typedef struct{
    int *number;
    int length;
}Sqlist;

//定义多项式
typedef struct{
    float coef; //系数
    int expn;   //指数
}data;

void InitSqlist(Sqlist &L);

void Sqlist_merge();

void InitSqlistdata(data L[],int x);

int Adddata(data L[]);

void SqlistdataSum(data A[],data B[],int A_max,int B_max);

void dataPrint(data L[],int C_max);
#endif // LINK_LIST_H_INCLUDED
