#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits>

//==========�ڽӾ���==========
#define INFINITY INT_MAX
#define MVNum 100

typedef int VerTexType;
typedef int ArcType;

typedef struct{
    VerTexType vexs[MVNum];     //�����
    ArcType arcs[MVNum][MVNum];     //�ڽӾ���
    int vexnum,arcnum;      //��ǰ�������ͱ���
}AMGraph;

//==========�ڽӱ�==========
#define MVNum 100

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode,*ArcList;

typedef struct VNode{
    VerTexType data;    //�洢������
    ArcNode *firstarc;  //ָ�룬ָ�������������д洢����Ϊ���������
}VNode,AdjList[MVNum];

typedef struct{
    AdjList vertices;   //����������ɵı�
    int vexnum,arcnum;  //�������ͱ���
}ALGraph;   //����ṹ��

//==========����==========
#define MAXQSIZE 100
#define QElemType int
typedef struct{
    QElemType *base;
    int front;
    int rear;
}SqQueue;

//��ʼ��������
void InitArcNode(ArcList &L);

//��ʼ������
void InitQueue(SqQueue &Q);

//����
void EnQueue(SqQueue &Q,QElemType e);

//��ӡ�����е�����
void SqQueue_print(SqQueue Q);

//�����ڽӾ���
void create_matrix(AMGraph &G);

//���Ҹ�Ԫ�����ڽӱ�ṹ�����������
int ALG_ver_search(ALGraph G,VerTexType n);

//�ж�ĳԪ���Ƿ��ڶ���
bool SqQueue_search(SqQueue Q,int index);

//�ڽӾ������ȱ����ĵݹ�
void Matrix_DFS_search(AMGraph G,int s,SqQueue &Q);

//�ڽӱ����ȱ����ĵݹ�
void AdjList_DFS_search(ALGraph G,int s,SqQueue &Q);

//�ڽӾ���Ĺ�ȱ����ĵݹ�
void Matrix_BFS_search(AMGraph &G,int s,SqQueue &Q);

//�ڽӱ�Ĺ�����ȱ����ĵݹ�
void AdjList_BFS_search(ALGraph G,int s,SqQueue &Q);

#endif // GRAPH_H_INCLUDED
