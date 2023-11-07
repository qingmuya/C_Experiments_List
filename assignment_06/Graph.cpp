#include "menu.h"
#include "Graph.h"
#include "Function.h"
#include <algorithm>

using namespace std;

//��������ͼ�ڽӾ���
void create_directed_graph_matrix(AMGraph &G){
    cout<<"��������ͼ�Ķ������ͱ���:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    //�������ȫ����Ϊ0
    for(int i = 0;i <= G.vexnum;i++){
        G.tag[i] = 0;
    }
    cout<<"��������ͼ�Ķ����ţ��Կո���:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }
    cout<<"��ʼ����ߣ�������ߵ������˵���Ȩ�أ��Կո�Ϊ���:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y,qz;
        cin>>x>>y>>qz;
        G.arcs[x][y] += 1;
        G.arcs[y][x] += 1;
        G.weight[x][y] = qz;
        G.weight[y][x] = qz;
    }
}

//��������ͼ�ڽӾ���
void create_undirected_graph_matrix(AMGraph &G){
    cout<<"��������ͼ�Ķ������ͱ���:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    //�������ȫ����Ϊ0
    for(int i = 0;i <= G.vexnum;i++){
        G.tag[i] = 0;
    }
    cout<<"��������ͼ�Ķ����ţ��Կո���:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }
    cout<<"��ʼ����ߣ�������ߵ������˵㣬�Կո�Ϊ���:"<<endl;
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
    /*����һ�����飺���ڴ����Ѿ�����������С�������Ľ��
      ����������飬�������򷽷������СȨֵ����ı�
      ͬʱ������ߵ���һ����㲻���������ڣ��������ж�����
      �������ڣ���θ���Ȩֵ��������㣿
      ���������ʹ�ö�ά���飬����С��Ȩֵ���±���ȡ�������ɡ�
      ��Ҫһ�������ж�G�е�Ԫ���Ƿ񶼽�������С�����������
    */

    int tree[G.vexnum];
    int num_of_tree = 1;
    tree[0] = start;

    //���������Ľڵ���г�ʼ�������ں�����whileѭ����ֹ�������ж�
    for(int i = 1;i < G.vexnum;i++){
        tree[i] = -1;
    }

    //����С��������Ԫ��û��������һֱѭ��
    while(tree[G.vexnum - 1] == -1){
        int G_weight[G.arcnum]; //��¼ÿ��������Ӧ��Ȩֵ
        //x��¼���ڱ���ѭ���У��ж������߱����뵽Ҫ�жϵ�����
        int x = 0;
        //������forѭ�����ڼ�����Ѿ�������С�������ĵ���������(���������ڵĽ��)������Ȩֵ
        for(int i = 0;i < num_of_tree;i++){
            for(int j = 0;j <= G.vexnum;j++){
                /*
                  ����forѭ������Ϊ�˱����Ѿ�����������������
                  ͬʱ����ֹ�ظ����Ԫ�ص�������
                  ���ձ��α������������ĳ��Ȼ���x
                */
                if(G.weight[tree[i]][j] != 0 && !judge_e(j,tree,num_of_tree)){
                    G_weight[x] = G.weight[tree[i]][j];
                    x++;
                }
            }
        }

        //���򣻳�ȡ��С��Ȩֵ
        sort(G_weight,G_weight + x);

        int start_index,last_index;  //��¼��СȨֵ��Ӧ������������յ�����
        //��������Ӧ���ҵ���СȨֵ��Ӧ�������յ�
        for(int i = 0;i < num_of_tree;i++){
            //cout<<"����ֵΪ��"<<tree[num_of_tree]<<endl;
            int ctrl_index = 0;//���ڿ������ѭ������ֹ
            for(int j = 1;j <= G.vexnum;j++){
                //cout<<"��ֵ֤Ϊ"<<G.weight[tree[i]][j]<<endl;
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

        //�����ӵĽڵ���ӵ���С����������
        tree[num_of_tree] = last_index;
        num_of_tree++;

        //����Ȩ��
        *min_weight = G_weight[0] + *min_weight;

        cout<<"("<<start_index<<","<<last_index<<") ";
    }
}
