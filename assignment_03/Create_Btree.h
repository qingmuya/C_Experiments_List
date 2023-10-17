#ifndef CREATE_BTREE_H_INCLUDED
#define CREATE_BTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct BiTNode{
    char data;//���������
    struct BiTNode *lchild,*rchild;//���Һ�����
}BiTNode,*BiTree;

//����������
void create_Btree(BiTree &T);

//��ӡ������ȫ���ڵ�
void print_Btree(BiTree &T);

#endif // CREATE_BTREE_H_INCLUDED
