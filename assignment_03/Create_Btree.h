#ifndef CREATE_BTREE_H_INCLUDED
#define CREATE_BTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct BiTNode{
    char data;//结点数据域
    struct BiTNode *lchild,*rchild;//左右孩子域
}BiTNode,*BiTree;

//创建二叉树
void create_Btree(BiTree &T);

//打印二叉树全部节点
void print_Btree(BiTree &T);

#endif // CREATE_BTREE_H_INCLUDED
