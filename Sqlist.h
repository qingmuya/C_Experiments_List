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

//顺序表初始化
void InitSqlist(Sqlist &L);
//顺序表输入
void Input(Sqlist &L);
//顺序表合并
void Sqlist_merge(Sqlist &A,Sqlist &B);
//多项式顺序表初始化
void InitSqlistdata(data L[],int x);
//多项式顺序表添加数值
int Adddata(data L[]);
//多项式顺序表求和
void SqlistdataSum(data A[],data B[],int A_max,int B_max);
//多项式顺序表打印
void dataPrint(data L[],int C_max);
#endif // LINK_LIST_H_INCLUDED
