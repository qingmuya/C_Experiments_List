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
    int tag[MVNum];    //标记数组
}AMGraph;

//创建有向图
void create_directed_graph_matrix(AMGraph &G);

//创建无向图
void create_undirected_graph_matrix(AMGraph &G);

//判断某个元素是否在数组中
bool judge_e(int e,int arg[],int num);

//最小生成树
void Matrix_search(AMGraph G,int start,int *min_weight);
#endif // GRAPH_H_INCLUDED
