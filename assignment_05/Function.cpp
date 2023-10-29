#include "menu.h"
#include "Graph.h"
#include "Function.h"

using namespace std;

//深度优先遍历（邻接矩阵）
void Matrix_DFS(AMGraph &G){
    //向邻接矩阵矩阵赋值
    create_matrix(G);
    SqQueue Q;
    InitQueue(Q);

    //输出邻接矩阵
    cout<<"邻接矩阵为："<<endl;
    for(int i = 1;i <= G.vexnum;i++){
        for(int j = 1;j <= G.vexnum;j++){
            cout<<G.arcs[i][j]<<" ";
        }
        cout<<"\n";
    }

    //开始遍历
    int start;
    cout<<"输入初始遍历顶点编号："<<endl;
    cin>>start;
    EnQueue(Q,start);
    Matrix_DFS_search(G,start,Q);
    cout<<"深度优先遍历（邻接矩阵）结果为：\n";
    //打印结果
    SqQueue_print(Q);
}

//深度优先遍历（邻接表）
void AdjList_DFS(ALGraph &G){
    //对邻接矩阵赋值
    cout<<"输入无向图的顶点数和边数："<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"输入无向图的顶点编号，以空格间隔:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vertices[i].data;
    }

    //初始化邻接表中每个单链表
    for(int i = 0;i < G.vexnum;i++){
        InitArcNode(G.vertices[i].firstarc);
    }

    //对单链表进行赋值
    cout<<"开始键入边;即键入边的两个端点即可，以空格为间隔:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        //先创建两个ArcNode结构体实例p，q；用于后续加入整体结构体的单链表
        ArcNode *p,*q;
        InitArcNode(p);
        InitArcNode(q);
        //先记录两个顶点，这两个顶点构成了一条边
        cin>>p->adjvex>>q->adjvex;
        //需要查找顶点名称在结构体数组中的下标
        int index_x = ALG_ver_search(G,p->adjvex);
        int index_y = ALG_ver_search(G,q->adjvex);

        p->adjvex = index_x;
        q->adjvex = index_y;

        //由于遍历是间断的向单链表插入值，要遍历到最后一位
        ArcNode *s = G.vertices[index_x].firstarc;
        ArcNode *r = G.vertices[index_y].firstarc;

        //赋值
        while(s->nextarc != NULL){
            s = s->nextarc;
        }
        while(r->nextarc != NULL){
            r = r->nextarc;
        }
        s->nextarc = q;
        r->nextarc = p;
    }

    //保留G中指针的位置，留在M里
    ALGraph M = G;
    //打印邻接表的内容
    cout<<"邻接表内容为："<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cout<<G.vertices[i].data<<":";
        G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
        while(G.vertices[i].firstarc != NULL){
            cout<<G.vertices[i].firstarc->adjvex<<" ";
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
        }
        cout<<endl;
    }

    //开始遍历
    SqQueue Q;
    InitQueue(Q);
    int start;
    cout<<"输入初始遍历顶点编号："<<endl;
    cin>>start;
    EnQueue(Q,start);
    AdjList_DFS_search(M,start,Q);
    cout<<"深度优先遍历（邻接表）结果为：\n";
    SqQueue_print(Q);
}

//广度优先遍历（邻接矩阵）
void Matrix_BFS(AMGraph &G){
    create_matrix(G);
    SqQueue Q;
    InitQueue(Q);

    int start;
    cout<<"输入初始遍历顶点编号："<<endl;
    cin>>start;
    EnQueue(Q,start);
    Matrix_BFS_search(G,start,Q);
    cout<<"广度优先遍历（邻接矩阵）结果为：\n";
    //打印结果
    SqQueue_print(Q);
}

//广度优先遍历（邻接表）
void AdjList_BFS(ALGraph &G){
    cout<<"输入无向图的顶点数和边数："<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"输入无向图的顶点编号，以空格间隔:"<<endl;
    for(int i = 0;i < G.vexnum;i++){
        cin>>G.vertices[i].data;
    }

    for(int i = 0;i < G.vexnum;i++){
        InitArcNode(G.vertices[i].firstarc);
    }

    cout<<"开始键入边;即键入边的两个端点即可，以空格为间隔:"<<endl;
    for(int i = 0;i < G.arcnum;i++){
        //先创建两个ArcNode结构体实例p，q；用于后续加入整体结构体的单链表
        ArcNode *p,*q;
        InitArcNode(p);
        InitArcNode(q);
        //先记录两个顶点，这两个顶点构成了一条边
        cin>>p->adjvex>>q->adjvex;
        //需要查找顶点名称在结构体数组中的下标
        int index_x = ALG_ver_search(G,p->adjvex);
        int index_y = ALG_ver_search(G,q->adjvex);

        p->adjvex = index_x;
        q->adjvex = index_y;

        //间断的插入，要遍历
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
    cout<<"输入初始遍历顶点编号："<<endl;
    cin>>start;
    EnQueue(Q,start);
    AdjList_BFS_search(G,start,Q);

    cout<<"广度优先遍历（邻接表）结果为：\n";
    SqQueue_print(Q);
}
