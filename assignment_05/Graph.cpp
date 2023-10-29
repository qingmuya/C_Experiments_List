#include "menu.h"
#include "Graph.h"
#include "Function.h"

using namespace std;

//初始化单链表
void InitArcNode(ArcList &L){
    L = new ArcNode;
    L->nextarc = NULL;
}

//对队列进行初始化
void InitQueue(SqQueue &Q){
    Q.base = new QElemType[MAXQSIZE];
    Q.front = Q.rear = 0;
}

//进队
void EnQueue(SqQueue &Q,QElemType e){
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}

//打印队列中的内容
void SqQueue_print(SqQueue Q){
    Q.front = 0;
    while(Q.front != Q.rear){
        cout<<Q.base[Q.front]<<" ";
        Q.front = (Q.front + 1) % MAXQSIZE;
    }
}

//深度优先遍历（邻接矩阵）的递归
void Matrix_DFS_search(AMGraph G,int s,SqQueue &Q){
    int start;
    for(int i = 1;i <= G.vexnum;i++){
        if(G.arcs[s][i] == 1){
            int index = 0;
            SqQueue P = Q;
            //在矩阵的此行遇到了值为1的点，将此值在队列中遍历，防止重复加入
            //如果没有重复，存入；如果有，跳过
            //index作为验证数字，如果值为1，说明有重复元素
            //                   如果值为0，说明没有重复元素

            //while循环判断Q中是否包含该元素
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

//查找顶点在结构体数组中的索引
int ALG_ver_search(ALGraph G,VerTexType n){
    for(int i = 0;i < G.vexnum;i++){
        if(n == G.vertices[i].data){
            //返回其索引
            return i;
        }
    }
}

//判断某元素是否在队中
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

//深度优先遍历（邻接表）的递归
void AdjList_DFS_search(ALGraph G,int s,SqQueue &Q){
    //向前移一位，有值
    G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
    //遍历判断
    while(G.vertices[s].firstarc != NULL){
        //没有重复：进行存入，递归
        if(!SqQueue_search(Q,G.vertices[s].firstarc->adjvex)){
            EnQueue(Q,G.vertices[s].firstarc->adjvex);
            AdjList_DFS_search(G,G.vertices[s].firstarc->adjvex,Q);
            //间断后可继续遍历
            G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
        }
        else{
            G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
        }
    }
}

//创建邻接矩阵
void create_matrix(AMGraph &G){
    cout<<"输入无向图的顶点数和边数:"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"输入无向图的顶点编号，以空格间隔:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vexs[i];
    }
    cout<<"开始键入边;即键入边的两个端点即可，以空格为间隔:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        int x,y;
        cin>>x>>y;
        G.arcs[x][y] += 1;
        G.arcs[y][x] += 1;
    }
}

//广度优先遍历（邻接矩阵）的递归
void Matrix_BFS_search(AMGraph &G,int s,SqQueue &Q){
    int start;
    SqQueue M;
    InitQueue(M);
    for(int i = 1;i <= G.vexnum;i++){
        if(G.arcs[s][i] == 1){
            int index = 0;
            //将Q复制到P，Q的指针不会挪动
            SqQueue P = Q;
            while(P.front != P.rear){
                //遇到重复，将验证值index赋值为1，跳出循环
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
    //广度遍历的精髓：每层都有队列，用队列进行遍历，牺牲性能
    while(M.front != M.rear){
        Matrix_BFS_search(G,M.base[M.front],Q);
        M.front++;
    }
}

//广度优先遍历（邻接表）的递归
void AdjList_BFS_search(ALGraph G,int s,SqQueue &Q){
    SqQueue M;
    InitQueue(M);
    G.vertices[s].firstarc = G.vertices[s].firstarc->nextarc;
    while(G.vertices[s].firstarc != NULL){
        //与深度优先遍历不同之处：开始递归位置不同
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
