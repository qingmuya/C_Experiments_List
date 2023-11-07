#include "menu.h"
#include "Graph.h"
#include "Function.h"

using namespace std;

void Min_Tree(AMGraph &G){
    int min_weight = 0;
    create_directed_graph_matrix(G);

    int start;
    cout<<"�����ʼ���������ţ�"<<endl;
    cin>>start;
    G.tag[start] = 1;

    cout<<"��С������";
    Matrix_search(G,start,&min_weight);
    cout<<"\n"<<"Ȩ�غ�="<<min_weight<<endl;
}

void Topo_sort(AMGraph &G){
    create_undirected_graph_matrix(G);
    //���Ӧ���ڽӾ���ÿ�еĺ;�����ȣ�ֻҪΪ0���������
    int topo[G.vexnum],num_of_topo = 1;   //��¼��ȵ�������Ѿ�������Ľڵ�����

    //���Ѿ�������Ľڵ���г�ʼ�������ں�����whileѭ����ֹ�������ж�
    for(int i = 0;i <= G.vexnum;i++){
        topo[i] = -1;
    }

    cout<<"����������Ϊ��";
    while(topo[G.vexnum - 1] == -1){
        //����������飬��ʼ���������и�ֵ
        int in[G.vexnum];
        for(int i = 0;i < G.vexnum;i++){
            in[i] = 0;
        }
        //ÿ�ζ�ˢ�£���¼ÿ���ڵ�����
        for(int i = 1;i < G.vexnum;i++){
            for(int j = 1;j <= G.vexnum;j++){
                in[i - 1] += G.arcs[j][i];
            }
        }

        //�жϽڵ������Ƿ�Ϊ0�����Ƿ������
        for(int i = 0;i <= G.vexnum;i++){
            if(in[i] == 0 && !judge_e(i + 1,topo,num_of_topo)){
                topo[num_of_topo - 1] = i + 1;
                num_of_topo++;
                cout<<topo[num_of_topo - 2]<<",";
                break;
            }
        }

        //����Ƚ���ˢ��
        for(int i = 1;i < G.vexnum;i++){
            G.arcs[topo[num_of_topo - 2]][i] = 0;
        }
    }
}
