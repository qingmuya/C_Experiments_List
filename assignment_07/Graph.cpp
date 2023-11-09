#include "menu.h"
#include "Graph.h"
#include "Function.h"
#include <algorithm>
#include <windows.h>

using namespace std;

void Earliest_time(AMGraph &G){
    create_directed_graph_matrix(G);

    /*
        ̰���㷨��һ��׷Ѱ�·������
        ��������·�����ȣ���ʹ��ʱ��
    */

    int max_length = 0; //��¼���·��
    int index_num;  //��¼����Ϊ0�Ľڵ�

    //�������Ϊ0�Ľڵ�
    for(int i = 1;i <= G.vexnum;i++){
        int index_weight = 0;   //�м���������ڼ���ÿ���ڵ�ĳ���
        for(int x = 1;x <= G.vexnum;x++){
            index_weight += G.weight[i][x];
        }
        if(index_weight == 0){
            index_num = i;
            break;
        }
    }

    //index����������Ǽ�¼�ؼ�·��
    int index[G.vexnum];
    //ʹ��index[0]������ؼ�·���Ľڵ�
    index[0] = 1;
    for(int i = 1;i <= G.vexnum;i++){
        index[i] = -1;
    }

    int next_index = 1; //��¼��һ����������ʼ�ڵ�
    index[index[0]] = 1;
    index[0]++;
    while(next_index != index_num){
        //��ȡ�·����Ѱ����һ����ʼ�ڵ�
        int max_weight = 0; //�м������������ȡ�·��
        int mid_index = next_index; //�м���������ڱ���
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

    cout<<"����������Ŀ��Ҫ��ʱ�䣺"<<max_length<<endl;
    cout<<"�ؼ����"<<endl;
    for(int i = 1;i < index[0] - 1;i++){
        cout<<index[i]<<"->"<<index[i + 1]<<endl;
    }
}

void access(AMGraph &G){
    create_directed_graph_matrix_2(G);

    int start;  //�������
    cout<<"����������"<<endl;
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
