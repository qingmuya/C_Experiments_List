#include "menu.h"
#include "Graph.h"
#include "Function.h"

using namespace std;

//������ȱ������ڽӾ���
void Matrix_DFS(AMGraph &G){
    //���ڽӾ������ֵ
    create_matrix(G);
    SqQueue Q;
    InitQueue(Q);

    //����ڽӾ���
    cout<<"�ڽӾ���Ϊ��"<<endl;
    for(int i = 1;i <= G.vexnum;i++){
        for(int j = 1;j <= G.vexnum;j++){
            cout<<G.arcs[i][j]<<" ";
        }
        cout<<"\n";
    }

    //��ʼ����
    int start;
    cout<<"�����ʼ���������ţ�"<<endl;
    cin>>start;
    EnQueue(Q,start);
    Matrix_DFS_search(G,start,Q);
    cout<<"������ȱ������ڽӾ��󣩽��Ϊ��\n";
    //��ӡ���
    SqQueue_print(Q);
}

//������ȱ������ڽӱ�
void AdjList_DFS(ALGraph &G){
    //���ڽӾ���ֵ
    cout<<"��������ͼ�Ķ������ͱ�����"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"��������ͼ�Ķ����ţ��Կո���:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vertices[i].data;
    }

    //��ʼ���ڽӱ���ÿ��������
    for(int i = 0;i < G.vexnum;i++){
        InitArcNode(G.vertices[i].firstarc);
    }

    //�Ե�������и�ֵ
    cout<<"��ʼ�����;������ߵ������˵㼴�ɣ��Կո�Ϊ���:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        //�ȴ�������ArcNode�ṹ��ʵ��p��q�����ں�����������ṹ��ĵ�����
        ArcNode *p,*q;
        InitArcNode(p);
        InitArcNode(q);
        //�ȼ�¼�������㣬���������㹹����һ����
        cin>>p->adjvex>>q->adjvex;
        //��Ҫ���Ҷ��������ڽṹ�������е��±�
        int index_x = ALG_ver_search(G,p->adjvex);
        int index_y = ALG_ver_search(G,q->adjvex);

        p->adjvex = index_x;
        q->adjvex = index_y;

        //���ڱ����Ǽ�ϵ����������ֵ��Ҫ���������һλ
        ArcNode *s = G.vertices[index_x].firstarc;
        ArcNode *r = G.vertices[index_y].firstarc;

        //��ֵ
        while(s->nextarc != NULL){
            s = s->nextarc;
        }
        while(r->nextarc != NULL){
            r = r->nextarc;
        }
        s->nextarc = q;
        r->nextarc = p;
    }

    //����G��ָ���λ�ã�����M��
    ALGraph M = G;
    //��ӡ�ڽӱ������
    cout<<"�ڽӱ�����Ϊ��"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cout<<G.vertices[i].data<<":";
        G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
        while(G.vertices[i].firstarc != NULL){
            cout<<G.vertices[i].firstarc->adjvex<<" ";
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
        }
        cout<<endl;
    }

    //��ʼ����
    SqQueue Q;
    InitQueue(Q);
    int start;
    cout<<"�����ʼ���������ţ�"<<endl;
    cin>>start;
    EnQueue(Q,start);
    AdjList_DFS_search(M,start,Q);
    cout<<"������ȱ������ڽӱ����Ϊ��\n";
    SqQueue_print(Q);
}

//������ȱ������ڽӾ���
void Matrix_BFS(AMGraph &G){
    create_matrix(G);
    SqQueue Q;
    InitQueue(Q);

    int start;
    cout<<"�����ʼ���������ţ�"<<endl;
    cin>>start;
    EnQueue(Q,start);
    Matrix_BFS_search(G,start,Q);
    cout<<"������ȱ������ڽӾ��󣩽��Ϊ��\n";
    //��ӡ���
    SqQueue_print(Q);
}

//������ȱ������ڽӱ�
void AdjList_BFS(ALGraph &G){
    cout<<"��������ͼ�Ķ������ͱ�����"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"��������ͼ�Ķ����ţ��Կո���:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vertices[i].data;
    }

    for(int i = 0;i < G.vexnum;i++){
        InitArcNode(G.vertices[i].firstarc);
    }

    cout<<"��ʼ�����;������ߵ������˵㼴�ɣ��Կո�Ϊ���:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        //�ȴ�������ArcNode�ṹ��ʵ��p��q�����ں�����������ṹ��ĵ�����
        ArcNode *p,*q;
        InitArcNode(p);
        InitArcNode(q);
        //�ȼ�¼�������㣬���������㹹����һ����
        cin>>p->adjvex>>q->adjvex;
        //��Ҫ���Ҷ��������ڽṹ�������е��±�
        int index_x = ALG_ver_search(G,p->adjvex);
        int index_y = ALG_ver_search(G,q->adjvex);

        p->adjvex = index_x;
        q->adjvex = index_y;

        //��ϵĲ��룬Ҫ����
        ArcNode *s = G.vertices[index_x].firstarc;
        ArcNode *r = G.vertices[index_y].firstarc;

        while(s->nextarc != NULL){
            s = s->nextarc;
        }
        while(r->nextarc != NULL){
            r = r->nextarc;
        }
        s->nextarc = q;
        r->nextarc = p;
    }

    SqQueue Q;
    InitQueue(Q);
    int start;
    cout<<"�����ʼ���������ţ�"<<endl;
    cin>>start;
    EnQueue(Q,start);
    AdjList_BFS_search(G,start,Q);

    cout<<"������ȱ������ڽӱ����Ϊ��\n";
    SqQueue_print(Q);
}
