#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//单链表结构体
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//多项式单链表结构体
typedef struct PNode{
    float coef;//系数
    int expn;//指数
    struct PNode *next;//指针
}PNode,*polynomial;

//初始化单链表结构体
void InitLNode(LinkList &L);
//初始化多项式单链表结构体
void InitPNode(polynomial &L);
//单链表插入函数
LinkList LNodeInsert(LinkList &L);
//多项式插入函数
polynomial PNodeInsert(polynomial &P);
//单链表合并函数
void LNode_merge(LinkList &A,LinkList &B);
//多项式合并函数
void PNode_merge(polynomial &A,polynomial &B);
//单链表打印函数
void PrintLNode(LinkList &L);
//多项式打印函数
void PrintPNode(polynomial &L);
#endif // LINKLIST_H_INCLUDED
