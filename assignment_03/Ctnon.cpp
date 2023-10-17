#include "Create_Btree.h"
#include "Ctnon.h"
#include "Cxbl.h"
#include "Dgbl.h"
#include "Fdgzxbl.h"
#include "menu.h"

void count_the_number_of_nodes(){
    //左右都为空就是叶子节点

    int i = 0,*tnon;//叶子节点的个数

    tnon = &i;

    BiTree T;

    create_Btree(T);

    Sum_the_num_of_node(T,tnon);

    printf("二叉树叶子节点的个数为：%d\n",*tnon);
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
