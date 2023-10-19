#ifndef CREATE_HUFFMAN_TREE_H_INCLUDED
#define CREATE_HUFFMAN_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

//使用同一个结构体貌似存在冲突，且C++不允许方法重写，只能创建多个结构体和同功能函数

//哈夫曼树的存储结构
typedef struct{
    int weight;  //结点的权重
    int parent, lchild, rchild;  //结点的双亲、左孩子、右孩子的下标
}HTNode,*HuffmanTree;

//创建哈夫曼树
void create_huffman_tree(HuffmanTree &HT,int n);
//返回两个最小值
void Select(HuffmanTree HT, int len, int &s1, int &s2);
//打印输出函数
void print(HuffmanTree HT,int n);

#endif // CREATE_HUFFMAN_TREE_H_INCLUDED
