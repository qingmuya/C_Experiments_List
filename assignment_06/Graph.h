#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

//==========�ڽӾ���==========
#define INFINITY INT_MAX
#define MVNum 100

typedef int VerTexType;
typedef int ArcType;

typedef struct{
    VerTexType vexs[MVNum];     //�����
    ArcType arcs[MVNum][MVNum];     //�ڽӾ���
    int vexnum,arcnum;      //��ǰ�������ͱ���
    int weight[MVNum][MVNum];   //���Ȩ��ֵ
    int tag[MVNum];    //�������
}AMGraph;

//��������ͼ
void create_directed_graph_matrix(AMGraph &G);

//��������ͼ
void create_undirected_graph_matrix(AMGraph &G);

//�ж�ĳ��Ԫ���Ƿ���������
bool judge_e(int e,int arg[],int num);

//��С������
void Matrix_search(AMGraph G,int start,int *min_weight);
#endif // GRAPH_H_INCLUDED
