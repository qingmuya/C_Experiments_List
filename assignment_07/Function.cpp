#include "menu.h"
#include "Graph.h"
#include "Function.h"
#include <algorithm>

using namespace std;

//创建有向图邻接矩阵
void create_directed_graph_matrix(AMGraph &G){
    cout<<"输入无向图的顶点数和边数:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"输入无向图的顶点编号，以空格间隔:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }
    cout<<"开始键入边，即键入边的两个端点与权重，以空格为间隔:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y,qz;
        cin>>x>>y>>qz;
        G.arcs[x][y] += 1;
        G.weight[x][y] = qz;
    }
}

//创建有向图邻接矩阵，特别适用于求路径
void create_directed_graph_matrix_2(AMGraph &G){
    cout<<"输入无向图的顶点数和边数:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"输入无向图的顶点编号，以空格间隔:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }

    for(int i = 1;i <= G.vexnum;i++){
        for(int x = 1;x <= G.vexnum;x++){
            if(x == i){
                G.weight[i][x] = 0;
            }
            else{
                G.weight[i][x] = -1;
            }
        }
    }

    cout<<"开始键入边，即键入边的两个端点与权重，以空格为间隔:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y,qz;
        cin>>x>>y>>qz;
        G.arcs[x][y] += 1;
        G.weight[x][y] = qz;
    }
}
