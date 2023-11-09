#include "menu.h"
#include "Graph.h"
#include "Function.h"
#include <algorithm>
#include <windows.h>

using namespace std;

void Earliest_time(AMGraph &G){
    create_directed_graph_matrix(G);

    /*
        贪心算法：一致追寻最长路径即可
        所求本质是路径长度，不使用时间
    */

    int max_length = 0; //记录最长的路径
    int index_num;  //记录出度为0的节点

    //求出出度为0的节点
    for(int i = 1;i <= G.vexnum;i++){
        int index_weight = 0;   //中间变量，用于计算每个节点的出度
        for(int x = 1;x <= G.vexnum;x++){
            index_weight += G.weight[i][x];
        }
        if(index_weight == 0){
            index_num = i;
            break;
        }
    }

    //index数组的作用是记录关键路径
    int index[G.vexnum];
    //使用index[0]来储存关键路径的节点
    index[0] = 1;
    for(int i = 1;i <= G.vexnum;i++){
        index[i] = -1;
    }

    int next_index = 1; //记录下一个遍历的起始节点
    index[index[0]] = 1;
    index[0]++;
    while(next_index != index_num){
        //求取最长路径，寻找下一个起始节点
        int max_weight = 0; //中间变量：用于求取最长路径
        int mid_index = next_index; //中间变量，用于遍历
        for(int i = 1;i <= G.vexnum;i++){
            if(G.weight[mid_index][i] >= max_weight){
                max_weight = G.weight[mid_index][i];
                next_index = i;
            }
        }
        index[index[0]] = next_index;
        index[0]++;
        max_length += max_weight;
    }

    cout<<"整个工程项目需要的时间："<<max_length<<endl;
    cout<<"关键活动；"<<endl;
    for(int i = 1;i < index[0] - 1;i++){
        cout<<index[i]<<"->"<<index[i + 1]<<endl;
    }
}

void access(AMGraph &G){
    create_directed_graph_matrix_2(G);

    int start;  //遍历起点
    cout<<"请键入出发点"<<endl;
    cin>>start;
    for(int i = 1;i <= G.vexnum;i++){
        cout<<start<<"->"<<i<<":";
        if(G.weight[start][i] == -1){
            cout<<"no path"<<endl;
        }else{
            cout<<G.weight[start][i]<<endl;
        }
    }
}
