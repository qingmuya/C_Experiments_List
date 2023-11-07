#include "menu.h"
#include "Graph.h"
#include "Function.h"
#include <algorithm>

using namespace std;

//创建无向图邻接矩阵
void create_directed_graph_matrix(AMGraph &G){
    cout<<"输入无向图的顶点数和边数:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    //标记数组全部置为0
    for(int i = 0;i <= G.vexnum;i++){
        G.tag[i] = 0;
    }
    cout<<"输入无向图的顶点编号，以空格间隔:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }
    cout<<"开始键入边，即键入边的两个端点与权重，以空格为间隔:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y,qz;
        cin>>x>>y>>qz;
        G.arcs[x][y] += 1;
        G.arcs[y][x] += 1;
        G.weight[x][y] = qz;
        G.weight[y][x] = qz;
    }
}

//创建有向图邻接矩阵
void create_undirected_graph_matrix(AMGraph &G){
    cout<<"输入无向图的顶点数和边数:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    //标记数组全部置为0
    for(int i = 0;i <= G.vexnum;i++){
        G.tag[i] = 0;
    }
    cout<<"输入无向图的顶点编号，以空格间隔:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }
    cout<<"开始键入边，即键入边的两个端点，以空格为间隔:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y;
        cin>>x>>y;
        G.arcs[x][y] += 1;
    }
}

bool judge_e(int e,int arg[],int num){
    for(int i = 0;i < num;i++){
        if(e == arg[i]){
            return true;
        }
    }
    return false;
}

void Matrix_search(AMGraph G,int start,int *min_weight){
    /*创建一个数组：用于储存已经被包含进最小生成树的结点
      根据这个数组，运用排序方法获得最小权值代表的边
      同时，这个边的另一个结点不能在数组内：即增加判断条件
      问题在于：如何根据权值获得两个点？
      解决方法：使用二维数组，将最小的权值的下标提取出来即可。
      需要一个函数判断G中的元素是否都进入了最小生成树：解决
    */

    int tree[G.vexnum];
    int num_of_tree = 1;
    tree[0] = start;

    //对生成树的节点进行初始化：便于后续的while循环终止条件的判断
    for(int i = 1;i < G.vexnum;i++){
        tree[i] = -1;
    }

    //若最小生成树的元素没有满，则一直循环
    while(tree[G.vexnum - 1] == -1){
        int G_weight[G.arcnum]; //记录每个边所对应的权值
        //x记录了在本次循环中，有多少条边被加入到要判断的数组
        int x = 0;
        //这两层for循环用于计算出已经加入最小生成树的点与其他点(不包含树内的结点)相连的权值
        for(int i = 0;i < num_of_tree;i++){
            for(int j = 0;j <= G.vexnum;j++){
                /*
                  两层for循环，是为了遍历已经加入生成树的数组
                  同时，防止重复添加元素到生成树
                  最终本次遍历的生成树的长度会是x
                */
                if(G.weight[tree[i]][j] != 0 && !judge_e(j,tree,num_of_tree)){
                    G_weight[x] = G.weight[tree[i]][j];
                    x++;
                }
            }
        }

        //排序；抽取最小的权值
        sort(G_weight,G_weight + x);

        int start_index,last_index;  //记录最小权值对应的起点索引和终点索引
        //接下来，应该找到最小权值对应的起点和终点
        for(int i = 0;i < num_of_tree;i++){
            //cout<<"树的值为："<<tree[num_of_tree]<<endl;
            int ctrl_index = 0;//用于控制外层循环的终止
            for(int j = 1;j <= G.vexnum;j++){
                //cout<<"验证值为"<<G.weight[tree[i]][j]<<endl;
                if(G_weight[0] == G.weight[tree[i]][j]){
                    start_index = tree[i];
                    last_index = j;
                    ctrl_index++;
                    break;
                }
            }
            if(ctrl_index != 0){
                break;
            }
        }

        //将连接的节点添加到最小生成树数组
        tree[num_of_tree] = last_index;
        num_of_tree++;

        //计算权重
        *min_weight = G_weight[0] + *min_weight;

        cout<<"("<<start_index<<","<<last_index<<") ";
    }
}
