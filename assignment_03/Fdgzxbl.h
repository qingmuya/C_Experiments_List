#ifndef FDGZXBL_H_INCLUDED
#define FDGZXBL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MaxSize 50

//栈结点定义
typedef struct node1{
    BiTree data[MaxSize];  //存放栈中的数据
    int top;  //存放栈顶指针
}SqStack;

void non_recursive_mid_order_traversal();

//初始一个空栈
void InitStack(SqStack &S);

//将中序递归遍历转为非递归算法
void InOrder(BiTree &T,SqStack &S);

//入栈，要判断栈是不是满了
bool Push(SqStack &S,BiTree x);

//出栈，判断是不是在栈空
bool Pop(SqStack &S,BiTree &x);

//判断栈是否为空
bool StackEmpty(SqStack &S);

#endif // FDGZXBL_H_INCLUDED
