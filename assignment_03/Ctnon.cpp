#include "Create_Btree.h"
#include "Ctnon.h"
#include "Cxbl.h"
#include "Dgbl.h"
#include "Fdgzxbl.h"
#include "menu.h"

void count_the_number_of_nodes(){
    //���Ҷ�Ϊ�վ���Ҷ�ӽڵ�

    int i = 0,*tnon;//Ҷ�ӽڵ�ĸ���

    tnon = &i;

    BiTree T;

    create_Btree(T);

    Sum_the_num_of_node(T,tnon);

    printf("������Ҷ�ӽڵ�ĸ���Ϊ��%d\n",*tnon);
}

void Sum_the_num_of_node(BiTree &T,int *i){
    if(T != NULL){
        if(T->lchild == NULL && T->rchild == NULL){
            *i = *i + 1;
        }
        Sum_the_num_of_node(T->lchild,i);
        Sum_the_num_of_node(T->rchild,i);
    }
}
