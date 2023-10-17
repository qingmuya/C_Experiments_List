#ifndef FDGZXBL_H_INCLUDED
#define FDGZXBL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MaxSize 50

//ջ��㶨��
typedef struct node1{
    BiTree data[MaxSize];  //���ջ�е�����
    int top;  //���ջ��ָ��
}SqStack;

void non_recursive_mid_order_traversal();

//��ʼһ����ջ
void InitStack(SqStack &S);

//������ݹ����תΪ�ǵݹ��㷨
void InOrder(BiTree &T,SqStack &S);

//��ջ��Ҫ�ж�ջ�ǲ�������
bool Push(SqStack &S,BiTree x);

//��ջ���ж��ǲ�����ջ��
bool Pop(SqStack &S,BiTree &x);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack &S);

#endif // FDGZXBL_H_INCLUDED
