#include "menu.h"
#include "Graph.h"
#include "Function.h"

using namespace std;

//��ʼ��������
void InitArcNode(ArcList &L){
    L = new ArcNode;
    L->nextarc = NULL;
}

//�Զ��н��г�ʼ��
void InitQueue(SqQueue &Q){
    Q.base = new QElemType[MAXQSIZE];
    Q.front = Q.rear = 0;
}

//����
void EnQueue(SqQueue &Q,QElemType e){
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}

//��ӡ�����е�����
void SqQueue_print(SqQueue Q){
    Q.front = 0;
    while(Q.front != Q.rear){
        cout<<Q.base[Q.front]<<" ";
        Q.front = (Q.front + 1) % MAXQSIZE;
    }
}

//������ȱ������ڽӾ��󣩵ĵݹ�
void Matrix_DFS_search(AMGraph G,int s,SqQueue &Q){
    int start;
    for(int i = 1;i <= G.vexnum;i++){
        if(G.arcs[s][i] == 1){
            int index = 0;
            SqQueue P = Q;
            //�ھ���Ĵ���������ֵΪ1�ĵ㣬����ֵ�ڶ����б�������ֹ�ظ�����
            //���û���ظ������룻����У�����
            //index��Ϊ��֤���֣����ֵΪ1��˵�����ظ�Ԫ��
            //                   ���ֵΪ0��˵��û���ظ�Ԫ��

            //whileѭ���ж�Q���Ƿ������Ԫ��
            while(P.front != P.rear){
                if(P.base[P.front] == i){
                    index = 1;
                    break;
                }
                P.front=(P.front+1) % MAXQSIZE;
            }

            if(index == 0){
                EnQueue(Q,i);
                start = i;
                Matrix_DFS_search(G,start,Q);
                return;
            }
        }
    }
}

//���Ҷ����ڽṹ�������е�����
int ALG_ver_search(ALGraph G,VerTexType n){
    for(int i = 0;i < G.vexnum;i++){
        if(n == G.vertices[i].data){
            //����������
            return i;
        }
    }
}

//�ж�ĳԪ���Ƿ��ڶ���
bool SqQueue_search(SqQueue Q,int index){
    Q.front = 0;
    while(Q.front != Q.rear){
        if(index == Q.base[Q.front]){
            return true;
        }
        Q.front=(Q.front+1) % MAXQSIZE;
    }
    return false;
}

//������ȱ������ڽӱ��ĵݹ�
void AdjList_DFS_search(ALGraph G,int s,SqQueue &Q){
    //��ǰ��һλ����ֵ
    G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
    //�����ж�
    while(G.vertices[s].firstarc != NULL){
        //û���ظ������д��룬�ݹ�
        if(!SqQueue_search(Q,G.vertices[s].firstarc->adjvex)){
            EnQueue(Q,G.vertices[s].firstarc->adjvex);
            AdjList_DFS_search(G,G.vertices[s].firstarc->adjvex,Q);
            //��Ϻ�ɼ�������
            G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
        }
        else{
            G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
        }
    }
}

//�����ڽӾ���
void create_matrix(AMGraph &G){
    cout<<"��������ͼ�Ķ������ͱ���:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"��������ͼ�Ķ����ţ��Կո���:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }
    cout<<"��ʼ�����;������ߵ������˵㼴�ɣ��Կո�Ϊ���:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y;
        cin>>x>>y;
        G.arcs[x][y] += 1;
        G.arcs[y][x] += 1;
    }
}

//������ȱ������ڽӾ��󣩵ĵݹ�
void Matrix_BFS_search(AMGraph &G,int s,SqQueue &Q){
    int start;
    SqQueue M;
    InitQueue(M);
    for(int i = 1;i <= G.vexnum;i++){
        if(G.arcs[s][i] == 1){
            int index = 0;
            //��Q���Ƶ�P��Q��ָ�벻��Ų��
            SqQueue P = Q;
            while(P.front != P.rear){
                //�����ظ�������ֵ֤index��ֵΪ1������ѭ��
                if(P.base[P.front] == i){
                    index = 1;
                    break;
                }
                P.front=(P.front+1) % MAXQSIZE;
            }

            if(index == 0){
                EnQueue(Q,i);
                EnQueue(M,i);
            }
        }
    }
    //��ȱ����ľ��裺ÿ�㶼�ж��У��ö��н��б�������������
    while(M.front != M.rear){
        Matrix_BFS_search(G,M.base[M.front],Q);
        M.front++;
    }
}

//������ȱ������ڽӱ��ĵݹ�
void AdjList_BFS_search(ALGraph G,int s,SqQueue &Q){
    SqQueue M;
    InitQueue(M);
    G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
    while(G.vertices[s].firstarc != NULL){
        //��������ȱ�����֮ͬ������ʼ�ݹ�λ�ò�ͬ
        if(!SqQueue_search(Q,G.vertices[s].firstarc->adjvex)){
            EnQueue(Q,G.vertices[s].firstarc->adjvex);
            EnQueue(M,G.vertices[s].firstarc->adjvex);
            G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
        }
        else{
            G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
        }
    }
    while(M.front != M.rear){
        AdjList_BFS_search(G,M.base[M.front],Q);
        M.front++;
    }
}
