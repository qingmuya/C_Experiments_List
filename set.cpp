#include "Sqlist.h"
#include "Linklist.h"
#include "set.h"

void menu(){
    printf("\t*****欢迎使用以下功能****\n");
    printf("\t0：退出\n");
    printf("\t1：线性表合并\n");
    printf("\t2：有序表合并\n");
    printf("\t3：稀疏多项式加法（顺序表）\n");
    printf("\t4：稀疏多项式加法（单链表）\n");
    printf("\t请选择数据结构类型：\n");
}

void refresh(){
    printf("\n");
    system("Pause");
    system("cls");
    menu();
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:
                Sqlist C,D;
                InitSqlist(C);
                InitSqlist(D);
                printf("输入第一个数组的值：\n");
                Input(C);
                printf("输入第二个数组的值：\n");
                Input(D);
                Sqlist_merge(C,D);
                refresh();
                break;
            case 2:
                LinkList A,B;
                printf("向单链表A中插入数值：\n");
                LNodeInsert(A);
                printf("向单链表B中插入数值：\n");
                LNodeInsert(B);
                LNode_merge(A,B);
                refresh();
                break;
            case 3:{
                int P_max,Q_max,maxexpn;
                printf("请输入两多项式中最大的指数：\n");
                scanf("%d",&maxexpn);
                data P[maxexpn],Q[maxexpn];
                InitSqlistdata(P,maxexpn);
                InitSqlistdata(Q,maxexpn);
                printf("输入多项式A的值：\n");
                P_max = Adddata(P);
                printf("输入完毕\n");
                printf("输入多项式B的值：\n");
                Q_max = Adddata(Q);
                printf("输入完毕\n");
                SqlistdataSum(P,Q,P_max,Q_max);
                refresh();
                break;
            }
            case 4:
                polynomial M,N;
                printf("向多项式A中插入数值：\n");
                PNodeInsert(M);
                printf("向多项式B中插入数值：\n");
                PNodeInsert(N);
                PNode_merge(M,N);
                refresh();
                break;
            default:
                printf("输入非法字符，重新键入：\n");
                break;
        }
    }
}
