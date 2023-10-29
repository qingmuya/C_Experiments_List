#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits>

//==========邻接矩阵==========
#define INFINITY INT_MAX
#define MVNum 100

typedef int VerTexType;
typedef int ArcType;

typedef struct{
    VerTexType vexs[MVNum];     //顶点表
    ArcType arcs[MVNum][MVNum];     //邻接矩阵
    int vexnum,arcnum;      //当前顶点数和边数
}AMGraph;

//==========邻接表==========
#define MVNum 100

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode,*ArcList;

typedef struct VNode{
    VerTexType data;    //存储的数据
    ArcNode *firstarc;  //指针，指向单链表，单链表中存储内容为顶点的连接
}VNode,AdjList[MVNum];

typedef struct{
    AdjList vertices;   //数组和链表构成的表
    int vexnum,arcnum;  //顶点数和边数
}ALGraph;   //整体结构体

//==========队列==========
#define MAXQSIZE 100
#define QElemType int
typedef struct{
    QElemType *base;
    int front;
    int rear;
}SqQueue;

//初始化单链表
void InitArcNode(ArcList &L);

//初始化队列
void InitQueue(SqQueue &Q);

//进队
void EnQueue(SqQueue &Q,QElemType e);

//打印队列中的内容
void SqQueue_print(SqQueue Q);

//创建邻接矩阵
void create_matrix(AMGraph &G);

//查找该元素在邻接表结构体数组的索引
int ALG_ver_search(ALGraph G,VerTexType n);

//判断某元素是否在队中
bool SqQueue_search(SqQueue Q,int index);

//邻接矩阵的深度遍历的递归
void Matrix_DFS_search(AMGraph G,int s,SqQueue &Q);

//邻接表的深度遍历的递归
void AdjList_DFS_search(ALGraph G,int s,SqQueue &Q);

//邻接矩阵的广度遍历的递归
void Matrix_BFS_search(AMGraph &G,int s,SqQueue &Q);

//邻接表的广度优先遍历的递归
void AdjList_BFS_search(ALGraph G,int s,SqQueue &Q);

#endif // GRAPH_H_INCLUDED
