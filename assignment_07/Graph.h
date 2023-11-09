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
}AMGraph;

//�������緢��ʱ��͹ؼ�·��
void Earliest_time(AMGraph &G);

//��ͨ·
void access(AMGraph &G);

#endif // GRAPH_H_INCLUDED
