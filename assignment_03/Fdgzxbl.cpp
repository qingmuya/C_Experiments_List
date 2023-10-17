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

//��ʼһ����ջ
void InitStack(SqStack &S){
    S.top=-1;   //��ʼʱ��ջ��ָ��ָ��-1
}

//������ݹ����תΪ�ǵݹ��㷨
void InOrder(BiTree &T,SqStack &S){
    InitStack(S);
    BiTree p = T;
    printf("�ǵݹ�����������Ϊ��");
    while(p || !StackEmpty(S)){
        if(p){
            Push(S,p);  //��ջ
            p=p->lchild;
        }
        else{
            Pop(S,p);
            printf("%c ",p->data);//���ʽ��
            p=p->rchild;
        }
    }
    printf("\n");
}

//��ջ��Ҫ�ж�ջ�ǲ�������
bool Push(SqStack &S,BiTree x){
    if(S.top==MaxSize-1){
        cout<<"ջ����!�޷���ջ"<<endl;
        return false;
    }
    S.data[++S.top]=x;
    return true;
}

//��ջ���ж��ǲ�����ջ��
bool Pop(SqStack &S,BiTree &x){
    if(S.top==-1){
        cout<<"˳��ջΪ��!���޷���ջ"<<endl;
        return false;
    }
    x=S.data[S.top--];
    return true;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack &S){
    if(S.top==-1){
        return true;   //ջ��
    }
    else{
        return false;  //����
    }
}
