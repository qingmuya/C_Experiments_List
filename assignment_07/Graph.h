#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

//==========邻接矩阵==========
#define INFINITY INT_MAX
#define MVNum 100

typedef int VerTexType;
typedef int ArcType;

typedef struct{
    VerTexType vexs[MVNum];     //顶点表
    ArcType arcs[MVNum][MVNum];     //邻接矩阵
    int vexnum,arcnum;      //当前顶点数和边数
    int weight[MVNum][MVNum];   //标记权重值
}AMGraph;

//计算最早发生时间和关键路径
void Earliest_time(AMGraph &G);

//求通路
void access(AMGraph &G);

#endif // GRAPH_H_INCLUDED
