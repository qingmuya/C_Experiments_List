#include "Create_Btree.h"
#include "Ctnon.h"
#include "Cxbl.h"
#include "Dgbl.h"
#include "Fdgzxbl.h"
#include "menu.h"

void non_recursive_mid_order_traversal(){
    BiTree T;
    SqStack S;
    create_Btree(T);
    InOrder(T,S);
}

//初始一个空栈
void InitStack(SqStack &S){
    S.top=-1;   //初始时，栈顶指针指向-1
}

//将中序递归遍历转为非递归算法
void InOrder(BiTree &T,SqStack &S){
    InitStack(S);
    BiTree p = T;
    printf("非递归中序遍历结果为：");
    while(p || !StackEmpty(S)){
        if(p){
            Push(S,p);  //入栈
            p=p->lchild;
        }
        else{
            Pop(S,p);
            printf("%c ",p->data);//访问结点
            p=p->rchild;
        }
    }
    printf("\n");
}

//入栈，要判断栈是不是满了
bool Push(SqStack &S,BiTree x){
    if(S.top==MaxSize-1){
        cout<<"栈满了!无法入栈"<<endl;
        return false;
    }
    S.data[++S.top]=x;
    return true;
}

//出栈，判断是不是在栈空
bool Pop(SqStack &S,BiTree &x){
    if(S.top==-1){
        cout<<"顺序栈为空!，无法出栈"<<endl;
        return false;
    }
    x=S.data[S.top--];
    return true;
}

//判断栈是否为空
bool StackEmpty(SqStack &S){
    if(S.top==-1){
        return true;   //栈空
    }
    else{
        return false;  //不空
    }
}
