#include "menu.h"
#include "Graph.h"
#include "Function.h"
#include <algorithm>

using namespace std;

//��������ͼ�ڽӾ���
void create_directed_graph_matrix(AMGraph &G){
    cout<<"��������ͼ�Ķ������ͱ���:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"��������ͼ�Ķ����ţ��Կո���:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }
    cout<<"��ʼ����ߣ�������ߵ������˵���Ȩ�أ��Կո�Ϊ���:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y,qz;
        cin>>x>>y>>qz;
        G.arcs[x][y] += 1;
        G.weight[x][y] = qz;
    }
}

//��������ͼ�ڽӾ����ر���������·��
void create_directed_graph_matrix_2(AMGraph &G){
    cout<<"��������ͼ�Ķ������ͱ���:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"��������ͼ�Ķ����ţ��Կո���:"<<endl;
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

    cout<<"��ʼ����ߣ�������ߵ������˵���Ȩ�أ��Կո�Ϊ���:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y,qz;
        cin>>x>>y>>qz;
        G.arcs[x][y] += 1;
        G.weight[x][y] = qz;
    }
}
