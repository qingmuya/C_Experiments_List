#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//������ṹ��
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//����ʽ������ṹ��
typedef struct PNode{
    float coef;//ϵ��
    int expn;//ָ��
    struct PNode *next;//ָ��
}PNode,*polynomial;

//��ʼ��������ṹ��
void InitLNode(LinkList &L);
//��ʼ������ʽ������ṹ��
void InitPNode(polynomial &L);
//��������뺯��
LinkList LNodeInsert(LinkList &L);
//����ʽ���뺯��
polynomial PNodeInsert(polynomial &P);
//������ϲ�����
void LNode_merge(LinkList &A,LinkList &B);
//����ʽ�ϲ�����
void PNode_merge(polynomial &A,polynomial &B);
//�������ӡ����
void PrintLNode(LinkList &L);
//����ʽ��ӡ����
void PrintPNode(polynomial &L);
#endif // LINKLIST_H_INCLUDED
