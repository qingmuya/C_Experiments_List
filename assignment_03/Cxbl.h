#ifndef CXBL_H_INCLUDED
#define CXBL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Create_Btree.h"

#define MaxSize 128

// 定义顺序队
typedef struct Queue
{
    int front;               // 队头指针（实际上不是指针，是一个标签）
    int rear;                // 队尾指针（实际上不是指针，是一个标签）
    BiTNode* data[MaxSize];   // 存放队中元素（保存指针的数组）
}SqQueue;                    // struct Queue 的别名


void layer_order_traversal();

#endif // CXBL_H_INCLUDED
