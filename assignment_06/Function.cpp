#include "menu.h"
#include "Graph.h"
#include "Function.h"

using namespace std;

void Min_Tree(AMGraph &G){
    int min_weight = 0;
    create_directed_graph_matrix(G);

    int start;
    cout<<"输入初始遍历顶点编号："<<endl;
    cin>>start;
    G.tag[start] = 1;

    cout<<"最小生成树";
    Matrix_search(G,start,&min_weight);
    cout<<"\n"<<"权重和="<<min_weight<<endl;
}

void Topo_sort(AMGraph &G){
    create_undirected_graph_matrix(G);
    //其对应的邻接矩阵，每列的和就是入度，只要为0，输出即可
    int topo[G.vexnum],num_of_topo = 1;   //记录入度的数组和已经被输出的节点数组

    //对已经被输出的节点进行初始化：便于后续的while循环终止条件的判断
    for(int i = 0;i <= G.vexnum;i++){
        topo[i] = -1;
    }

    cout<<"拓朴排序结果为：";
    while(topo[G.vexnum - 1] == -1){
        //创建入度数组，初始化，随后进行赋值
        int in[G.vexnum];
        for(int i = 0;i < G.vexnum;i++){
            in[i] = 0;
        }
        //每次都刷新，记录每个节点的入度
        for(int i = 1;i < G.vexnum;i++){
            for(int j = 1;j <= G.vexnum;j++){
                in[i - 1] += G.arcs[j][i];
            }
        }

        //判断节点的入度是否为0，且是否输出过
        for(int i = 0;i <= G.vexnum;i++){
            if(in[i] == 0 && !judge_e(i + 1,topo,num_of_topo)){
                topo[num_of_topo - 1] = i + 1;
                num_of_topo++;
                cout<<topo[num_of_topo - 2]<<",";
                break;
            }
        }

        //对入度进行刷新
        for(int i = 1;i < G.vexnum;i++){
            G.arcs[topo[num_of_topo - 2]][i] = 0;
        }
    }
}
