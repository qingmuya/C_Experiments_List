#ifndef CXBL_H_INCLUDED
#define CXBL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Create_Btree.h"

#define MaxSize 128

// ����˳���
typedef struct Queue
{
    int front;               // ��ͷָ�루ʵ���ϲ���ָ�룬��һ����ǩ��
    int rear;                // ��βָ�루ʵ���ϲ���ָ�룬��һ����ǩ��
    BiTNode* data[MaxSize];   // ��Ŷ���Ԫ�أ�����ָ������飩
}SqQueue;                    // struct Queue �ı���


void layer_order_traversal();

#endif // CXBL_H_INCLUDED
